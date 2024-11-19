#pragma once

#include "esphome/components/sensor/sensor.h"
#include "../roomba.h"

namespace esphome {
namespace roomba {

class RoombaSensor : public PollingComponent, public RoombaClient {
 public:
  void update() override;
  void dump_config() override;

  void set_voltage_sensor(sensor::Sensor *sensor) { this->voltage_sensor_ = sensor; }
  void set_current_sensor(sensor::Sensor *sensor) { this->current_sensor_ = sensor; }
  void set_battery_charge_sensor(sensor::Sensor *sensor) { this->battery_charge_sensor_ = sensor; }
  void set_battery_capacity_sensor(sensor::Sensor *sensor) { this->battery_capacity_sensor_ = sensor; }
  void set_battery_percent_sensor(sensor::Sensor *sensor) { this->battery_percent_sensor_ = sensor; }
  void set_battery_temperature_sensor(sensor::Sensor *sensor) { this->battery_temperature_sensor_ = sensor; }
  void set_drive_speed_sensor(sensor::Sensor *sensor) { this->drive_speed_sensor_ = sensor; }
  void set_main_brush_current_sensor(sensor::Sensor *sensor) { this->main_brush_current_sensor_ = sensor; }
  void set_side_brush_current_sensor(sensor::Sensor *sensor) { this->side_brush_current_sensor_ = sensor; }

 protected:
  sensor::Sensor *voltage_sensor_{nullptr};
  sensor::Sensor *current_sensor_{nullptr};
  sensor::Sensor *battery_charge_sensor_{nullptr};
  sensor::Sensor *battery_capacity_sensor_{nullptr};
  sensor::Sensor *battery_percent_sensor_{nullptr};
  sensor::Sensor *battery_temperature_sensor_{nullptr};
  sensor::Sensor *drive_speed_sensor_{nullptr};
  sensor::Sensor *main_brush_current_sensor_{nullptr};
  sensor::Sensor *side_brush_current_sensor_{nullptr};
};

}  // namespace roomba
}  // namespace esphome
