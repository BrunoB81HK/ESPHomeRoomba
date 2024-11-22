#pragma once

#include <unordered_map>
#include <utility>
#include <vector>

#include "esphome.h"
#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

#include "roomba_enums.h"
#include "roomba_structs.h"

namespace esphome {
namespace roomba {

class RoombaComponent : public PollingComponent {
  friend class RoombaBinarySensor;
  friend class RoombaSensor;
  friend class RoombaTextSensor;

 public:
  // ESPHome
  void setup() override;
  void update() override;
  void dump_config() override;

  // Setters
  void set_brc_pin(uint8_t pin) { this->brc_pin_ = pin; }
  void set_lazy_650(bool enabled) { this->lazy_650_enabled_ = enabled; }
  void set_uart(uart::UARTComponent *uart) { this->uart_ = uart; }

  // Getters
  bool is_ready() { return this->ready_; }

 protected:
  // UART
  void available() { this->uart_->available(); }

  void flush() { this->uart_->flush(); }

  void write(Command command, void *data, size_t size);
  void write(Command command) { this->write(command, nullptr, 0); }
  template<typename T> void write(Command command, T data) { this->write(command, &data, sizeof(data)); }

  bool read(void *data, size_t size);
  template<typename T> bool read(T &data) { return this->read(&data, sizeof(data)); }

  uart::UARTComponent *uart_{nullptr};

 protected:
  // Command
  void reset() { this->write(Command::Reset); }
  void start() { this->write(Command::Start); }
  void stop() { this->write(Command::Stop); }
  void baud(Baud baud) { this->write(Command::Baud, +baud); }
  // Mode
  void safe_mode() { this->write(Command::Safe); }
  void full_mode() { this->write(Command::Full); }
  // Cleaning
  void clean() { this->write(Command::Clean); }
  void max() { this->write(Command::Max); }
  void spot() { this->write(Command::Spot); }
  void seek_dock() { this->write(Command::SeekDock); }
  void power() { this->write(Command::Power); }
  void schedule(std::unordered_map<Weekday, std::pair<uint8_t, uint8_t>> schedule);
  void set_day_time(Weekday day, uint8_t hour, uint8_t minute);
  // Actuator
  void drive();
  void drive_direct();
  void drive_pwm();
  void motors();
  void motors_pwm();
  void leds();
  void leds_scheduling();
  void leds_digit_raw();
  void leds_digit_ascii();
  void buttons();
  void song();
  void play();
  // Input
  void sensors(SensorPackets packet_id) { this->write(Command::Sensors, packet_id); }
  void query_list();
  void stream();
  void stream_pause_resume();
  void control();

 protected:
  // Sensors values
  SensorsValues sensors_values_;

 protected:
  void brc_wakeup();
  void wake_on_dock();

  uint8_t brc_pin_{0};
  bool lazy_650_enabled_{false};

  bool ready_{false};
  int last_wakeup_time_{0};
  bool was_cleaning_{false};
  bool was_docked_{false};
  Activity activity_{Activity::Docked};
};

class RoombaClient {
 public:
  void set_roomba(RoombaComponent *roomba) { this->roomba_ = roomba; }

 protected:
  RoombaComponent *roomba_;
};

}  // namespace roomba
}  // namespace esphome
