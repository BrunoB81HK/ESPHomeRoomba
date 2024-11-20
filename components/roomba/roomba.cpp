#include "roomba.h"

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
  SensorsValues tmp_sensors_values;
  if (!this->read(tmp_sensors_values)) {
    ESP_LOGW(TAG, "Sensors values update failed");
    return;
  }

  this->sensors_values = std::move(tmp_sensors_values);

  // Set the activity
  this->was_cleaning_ = false;
  this->was_docked_ = false;
  const auto &current = this->sensors_values.current;

  if (current > -50)
    this->was_docked_ = true;
  else if (current < -300)
    this->was_cleaning_ = true;
}

void RoombaComponent::dump_config() {}

void RoombaComponent::write(RoombaCommands command, void *data, size_t size) {
  this->uart_->write(static_cast<uint8_t>(command));
  this->uart_->write_array(static_cast<uint8_t *>(data), size);
}

bool RoombaComponent::read(void *data, size_t size) {
  return this->uart_->read_array(reinterpret_cast<uint8_t *>(data), size);
}

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
