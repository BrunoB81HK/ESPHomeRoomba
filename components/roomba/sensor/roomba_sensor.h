#pragma once

#include "esphome/components/sensor/sensor.h"

#include "../roomba.h"

namespace esphome {
namespace roomba {

class RoombaSensor : public PollingComponent, public RoombaClient {
 public:
  void update() override;
  void dump_config() override;

  void set_dirt_detect_sensor(sensor::Sensor *sensor) { this->dirt_detect_sensor_ = sensor; }
  void set_ir_byte_omni_sensor(sensor::Sensor *sensor) { this->ir_byte_omni_sensor_ = sensor; }
  void set_ir_byte_left_sensor(sensor::Sensor *sensor) { this->ir_byte_left_sensor_ = sensor; }
  void set_ir_byte_right_sensor(sensor::Sensor *sensor) { this->ir_byte_right_sensor_ = sensor; }
  void set_distance_sensor(sensor::Sensor *sensor) { this->distance_sensor_ = sensor; }
  void set_angle_sensor(sensor::Sensor *sensor) { this->angle_sensor_ = sensor; }
  void set_voltage_sensor(sensor::Sensor *sensor) { this->voltage_sensor_ = sensor; }
  void set_current_sensor(sensor::Sensor *sensor) { this->current_sensor_ = sensor; }
  void set_battery_temperature_sensor(sensor::Sensor *sensor) { this->battery_temperature_sensor_ = sensor; }
  void set_battery_charge_sensor(sensor::Sensor *sensor) { this->battery_charge_sensor_ = sensor; }
  void set_battery_capacity_sensor(sensor::Sensor *sensor) { this->battery_capacity_sensor_ = sensor; }
  void set_battery_percent_sensor(sensor::Sensor *sensor) { this->battery_percent_sensor_ = sensor; }
  void set_wall_signal_sensor(sensor::Sensor *sensor) { this->wall_signal_sensor_ = sensor; }
  void set_cliff_left_signal_sensor(sensor::Sensor *sensor) { this->cliff_left_signal_sensor_ = sensor; }
  void set_cliff_front_left_signal_sensor(sensor::Sensor *sensor) { this->cliff_front_left_signal_sensor_ = sensor; }
  void set_cliff_front_right_signal_sensor(sensor::Sensor *sensor) { this->cliff_front_right_signal_sensor_ = sensor; }
  void set_cliff_right_signal_sensor(sensor::Sensor *sensor) { this->cliff_right_signal_sensor_ = sensor; }
  void set_song_number_sensor(sensor::Sensor *sensor) { this->song_number_sensor_ = sensor; }
  void set_number_of_stream_packets_sensor(sensor::Sensor *sensor) { this->number_of_stream_packets_sensor_ = sensor; }
  void set_requested_velocity_sensor(sensor::Sensor *sensor) { this->requested_velocity_sensor_ = sensor; }
  void set_requested_radius_sensor(sensor::Sensor *sensor) { this->requested_radius_sensor_ = sensor; }
  void set_requested_right_velocity_sensor(sensor::Sensor *sensor) { this->requested_right_velocity_sensor_ = sensor; }
  void set_requested_left_velocity_sensor(sensor::Sensor *sensor) { this->requested_left_velocity_sensor_ = sensor; }
  void set_left_encoder_counts_sensor(sensor::Sensor *sensor) { this->left_encoder_counts_sensor_ = sensor; }
  void set_right_encoder_counts_sensor(sensor::Sensor *sensor) { this->right_encoder_counts_sensor_ = sensor; }
  void set_light_bump_left_signal_sensor(sensor::Sensor *sensor) { this->light_bump_left_signal_sensor_ = sensor; }
  void set_light_bump_front_left_signal_sensor(sensor::Sensor *sensor) {
    this->light_bump_front_left_signal_sensor_ = sensor;
  }
  void set_light_bump_center_left_signal_sensor(sensor::Sensor *sensor) {
    this->light_bump_center_left_signal_sensor_ = sensor;
  }
  void set_light_bump_center_right_signal_sensor(sensor::Sensor *sensor) {
    this->light_bump_center_right_signal_sensor_ = sensor;
  }
  void set_light_bump_front_right_signal_sensor(sensor::Sensor *sensor) {
    this->light_bump_front_right_signal_sensor_ = sensor;
  }
  void set_light_bump_right_signal_sensor(sensor::Sensor *sensor) { this->light_bump_right_signal_sensor_ = sensor; }
  void set_left_motor_current_sensor(sensor::Sensor *sensor) { this->left_motor_current_sensor_ = sensor; }
  void set_right_motor_current_sensor(sensor::Sensor *sensor) { this->right_motor_current_sensor_ = sensor; }
  void set_main_brush_current_sensor(sensor::Sensor *sensor) { this->main_brush_current_sensor_ = sensor; }
  void set_side_brush_current_sensor(sensor::Sensor *sensor) { this->side_brush_current_sensor_ = sensor; }

 protected:
  sensor::Sensor *dirt_detect_sensor_{nullptr};
  sensor::Sensor *ir_byte_omni_sensor_{nullptr};
  sensor::Sensor *distance_sensor_{nullptr};
  sensor::Sensor *angle_sensor_{nullptr};
  sensor::Sensor *voltage_sensor_{nullptr};
  sensor::Sensor *current_sensor_{nullptr};
  sensor::Sensor *battery_temperature_sensor_{nullptr};
  sensor::Sensor *battery_charge_sensor_{nullptr};
  sensor::Sensor *battery_capacity_sensor_{nullptr};
  sensor::Sensor *battery_percent_sensor_{nullptr};
  sensor::Sensor *wall_signal_sensor_{nullptr};
  sensor::Sensor *cliff_left_signal_sensor_{nullptr};
  sensor::Sensor *cliff_front_left_signal_sensor_{nullptr};
  sensor::Sensor *cliff_front_right_signal_sensor_{nullptr};
  sensor::Sensor *cliff_right_signal_sensor_{nullptr};
  sensor::Sensor *song_number_sensor_{nullptr};
  sensor::Sensor *number_of_stream_packets_sensor_{nullptr};
  sensor::Sensor *requested_velocity_sensor_{nullptr};
  sensor::Sensor *requested_radius_sensor_{nullptr};
  sensor::Sensor *requested_right_velocity_sensor_{nullptr};
  sensor::Sensor *requested_left_velocity_sensor_{nullptr};
  sensor::Sensor *left_encoder_counts_sensor_{nullptr};
  sensor::Sensor *right_encoder_counts_sensor_{nullptr};
  sensor::Sensor *light_bump_left_signal_sensor_{nullptr};
  sensor::Sensor *light_bump_front_left_signal_sensor_{nullptr};
  sensor::Sensor *light_bump_center_left_signal_sensor_{nullptr};
  sensor::Sensor *light_bump_center_right_signal_sensor_{nullptr};
  sensor::Sensor *light_bump_front_right_signal_sensor_{nullptr};
  sensor::Sensor *light_bump_right_signal_sensor_{nullptr};
  sensor::Sensor *ir_byte_left_sensor_{nullptr};
  sensor::Sensor *ir_byte_right_sensor_{nullptr};
  sensor::Sensor *left_motor_current_sensor_{nullptr};
  sensor::Sensor *right_motor_current_sensor_{nullptr};
  sensor::Sensor *main_brush_current_sensor_{nullptr};
  sensor::Sensor *side_brush_current_sensor_{nullptr};
};

}  // namespace roomba
}  // namespace esphome
