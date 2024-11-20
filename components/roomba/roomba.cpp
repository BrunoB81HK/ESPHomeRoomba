#include "roomba.h"

#include <array>

#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome {
namespace roomba {

constexpr char *TAG = "roomba";
constexpr int WAKE_UP_INTERVAL = 50000;

void RoombaComponent::setup() {
  if (this->lazy_650_enabled_) {
    // High-impedence on the BRC_PIN
    // see
    // https://github.com/johnboiles/esp-roomba-mqtt/commit/fa9af14376f740f366a9ecf4cb59dec2419deeb0#diff-34d21af3c614ea3cee120df276c9c4ae95053830d7f1d3deaf009a4625409ad2R140
    pinMode(this->brc_pin_, INPUT);
  } else {
    pinMode(this->brc_pin_, OUTPUT);
    digitalWrite(this->brc_pin_, HIGH);
  }
}

void RoombaComponent::update() {
  if (this->lazy_650_enabled_) {
    // Wakeup the roomba at fixed intervals
    long now = millis();
    if (now - this->last_wakeup_time_ > WAKE_UP_INTERVAL) {
      ESP_LOGD(TAG, "Time to wakeup");
      this->last_wakeup_time_ = now;
      if (!this->was_cleaning_) {
        if (this->was_docked_) {
          wake_on_dock();
        } else {
          this->brc_wakeup();
        }
      } else {
        this->brc_wakeup();
      }
    }
  }

  // Flush the serial buffer
  this->flush();

  // Get sensor values
  this->sensors(RoombaSensorPackets::Group7to58);
  RoombaSensorsValues tmp_sensors_values;
  if (!this->read(tmp_sensors_values)) {
    ESP_LOGW(TAG, "Sensors values update failed");
    return;
  }

  this->sensors_values_ = std::move(tmp_sensors_values);

  // Set the activity
  const auto &current = this->sensors_values_.current;
  const auto &charging = this->sensors_values_.charging_state;
  bool isCharging = charging == RoombaChargeState::ReconditioningCharging ||
                    charging == RoombaChargeState::FullCharging || charging == RoombaChargeState::TrickleCharging;

  if (current > -50)
    this->activity_ = RoombaActivity::Docked;
  else if (isCharging)
    this->activity_ = RoombaActivity::Charging;
  else if (current < -300)
    this->activity_ = RoombaActivity::Cleaning;
  else
    this->activity_ = RoombaActivity::Lost;

  this->was_cleaning_ = ths->activity_ == RoombaActivity::Cleaning;
  this->was_docked_ = ths->activity_ == RoombaActivity::Docked;
}

void RoombaComponent::dump_config() {}

void RoombaComponent::write(RoombaCommands command, void *data, size_t size) {
  this->uart_->write(static_cast<uint8_t>(command));
  this->uart_->write_array(static_cast<uint8_t *>(data), size);
}

bool RoombaComponent::read(void *data, size_t size) {
  return this->uart_->read_array(reinterpret_cast<uint8_t *>(data), size);
}

void RoombaComponent::schedule(std::unordered_map<RoombaWeekday, std::pair<uint8_t, uint8_t>> schedule) {
  std::array<uint8_t, 15> schedule_array;
  for (const auto &[day, time] : schedule) {
    schedule_array[0] |= 1 << static_cast<uint8_t>(day);

    size_t index = 2 + static_cast<uint8_t>(day) * 2;
    schedule_array[index] = time.first;
    schedule_array[index + 1] = time.second;
  }

  this->write(RoombaCommands::Schedule, schedule_array, sizeof(schedule_array));
}

void RoombaComponent::set_day_time(RoombaWeekday day, uint8_t hour, uint8_t minute) {
  this->write(RoombaCommands::SetDayTime, {static_cast<uint8_t>(day), hour, minutes}, 3);
}

void RoombaComponent::drive() { this->write(RoombaCommands::Drive); }

void RoombaComponent::drive_direct() { this->write(RoombaCommands::DriveDirect); }

void RoombaComponent::drive_pwm() { this->write(RoombaCommands::DrivePWM); }

void RoombaComponent::motors() { this->write(RoombaCommands::Motors); }

void RoombaComponent::motors_pwm() { this->write(RoombaCommands::MotorsPWM); }

void RoombaComponent::leds() { this->write(RoombaCommands::LEDs); }

void RoombaComponent::leds_scheduling() { this->write(RoombaCommands::LEDsScheduling); }

void RoombaComponent::leds_digit_raw() { this->write(RoombaCommands::LEDsDigitRaw); }

void RoombaComponent::leds_digit_ascii() { this->write(RoombaCommands::LEDsDigitASCII); }

void RoombaComponent::buttons() { this->write(RoombaCommands::Buttons); }

void RoombaComponent::song() { this->write(RoombaCommands::Song); }

void RoombaComponent::play() { this->write(RoombaCommands::Play); }

void RoombaComponent::query_list() { this->write(RoombaCommands::QueryList); }

void RoombaComponent::stream() { this->write(RoombaCommands::Stream); }

void RoombaComponent::stream_pause_resume() { this->write(RoombaCommands::StreamPauseResume); }

void RoombaComponent::control() { this->write(RoombaCommands::Control); }

void RoombaComponent::brc_wakeup() {
  if (this->lazy_650_enabled_) {
    ESP_LOGD(TAG, "brc_wakeup");
    pinMode(this->brc_pin_, OUTPUT);
    digitalWrite(this->brc_pin_, LOW);
    delay(200);
    pinMode(this->brc_pin_, OUTPUT);
    delay(200);
    this->start();
  } else {
    digitalWrite(this->brc_pin_, LOW);
    delay(1000);
    digitalWrite(this->brc_pin_, HIGH);
    delay(100);
  }
}

void RoombaComponent::wake_on_dock() {
  ESP_LOGD(TAG, "wake_on_dock");
  this->brc_wakeup();
  // Some black magic from @AndiTheBest to keep the Roomba awake on the dock
  // See https://github.com/johnboiles/esp-roomba-mqtt/issues/3#issuecomment-402096638
  delay(10);
  this->clean();
  delay(150);
  this->dock();
}

}  // namespace roomba
}  // namespace esphome
