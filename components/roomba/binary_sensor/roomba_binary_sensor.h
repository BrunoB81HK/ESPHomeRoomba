#pragma once

#include "esphome/components/binary_sensor/binary_sensor.h"
#include "../roomba.h"

namespace esphome {
namespace roomba {

class RoombaBinarySensor : public PollingComponent, public RoombaClient {
 public:
  void update() override;
  void dump_config() override;

  void set_vacuum_sensor(binary_sensor::BinarySensor *binary_sensor) { this->vacuum_sensor_ = binary_sensor; }
  void set_left_wheel_drop_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->left_wheel_drop_sensor_ = binary_sensor;
  }
  void set_right_wheel_drop_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->right_wheel_drop_sensor_ = binary_sensor;
  }
  void set_left_bumps_sensor(binary_sensor::BinarySensor *binary_sensor) { this->left_bumps_sensor_ = binary_sensor; }
  void set_right_bumps_sensor(binary_sensor::BinarySensor *binary_sensor) { this->right_bumps_sensor_ = binary_sensor; }
  void set_wall_sensor(binary_sensor::BinarySensor *binary_sensor) { this->wall_sensor_ = binary_sensor; }
  void set_left_cliff_sensor(binary_sensor::BinarySensor *binary_sensor) { this->left_cliff_sensor_ = binary_sensor; }
  void set_front_left_cliff_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->front_left_cliff_sensor_ = binary_sensor;
  }
  void set_front_right_cliff_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->front_right_cliff_sensor_ = binary_sensor;
  }
  void set_right_cliff_sensor(binary_sensor::BinarySensor *binary_sensor) { this->right_cliff_sensor_ = binary_sensor; }
  void set_virtual_wall_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->virtual_wall_sensor_ = binary_sensor;
  }
  void set_side_brush_overcurrent_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->side_brush_overcurrent_sensor_ = binary_sensor;
  }
  void set_main_brush_overcurrent_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->main_brush_overcurrent_sensor_ = binary_sensor;
  }
  void set_right_wheel_overcurrent_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->right_wheel_overcurrent_sensor_ = binary_sensor;
  }
  void set_left_wheel_overcurrent_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->left_wheel_overcurrent_sensor_ = binary_sensor;
  }
  void set_clean_button_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->clean_button_sensor_ = binary_sensor;
  }
  void set_spot_button_sensor(binary_sensor::BinarySensor *binary_sensor) { this->spot_button_sensor_ = binary_sensor; }
  void set_dock_button_sensor(binary_sensor::BinarySensor *binary_sensor) { this->dock_button_sensor_ = binary_sensor; }
  void set_minute_button_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->minute_button_sensor_ = binary_sensor;
  }
  void set_hour_button_sensor(binary_sensor::BinarySensor *binary_sensor) { this->hour_button_sensor_ = binary_sensor; }
  void set_day_button_sensor(binary_sensor::BinarySensor *binary_sensor) { this->day_button_sensor_ = binary_sensor; }
  void set_schedule_button_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->schedule_button_sensor_ = binary_sensor;
  }
  void set_clock_button_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->clock_button_sensor_ = binary_sensor;
  }
  void set_internal_charger_charging_source_available_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->internal_charger_charging_source_available_sensor_ = binary_sensor;
  }
  void set_home_base_charging_source_available_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->home_base_charging_source_available_sensor_ = binary_sensor;
  }
  void set_song_playing_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->song_playing_sensor_ = binary_sensor;
  }
  void set_left_light_bumper_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->left_light_bumper_sensor_ = binary_sensor;
  }
  void set_left_front_light_bumper_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->left_front_light_bumper_sensor_ = binary_sensor;
  }
  void set_left_center_light_bumper_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->left_center_light_bumper_sensor_ = binary_sensor;
  }
  void set_right_center_light_bumper_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->right_center_light_bumper_sensor_ = binary_sensor;
  }
  void set_right_front_light_bumper_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->right_front_light_bumper_sensor_ = binary_sensor;
  }
  void set_right_light_bumper_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->right_light_bumper_sensor_ = binary_sensor;
  }
  void set_toggling_stasis_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->toggling_stasis_sensor_ = binary_sensor;
  }
  void set_disabled_stasis_sensor(binary_sensor::BinarySensor *binary_sensor) {
    this->disabled_stasis_sensor_ = binary_sensor;
  }

 protected:
  binary_sensor::BinarySensor *vacuum_sensor_{nullptr};
  binary_sensor::BinarySensor *left_wheel_drop_sensor_{nullptr};
  binary_sensor::BinarySensor *right_wheel_drop_sensor_{nullptr};
  binary_sensor::BinarySensor *left_bumps_sensor_{nullptr};
  binary_sensor::BinarySensor *right_bumps_sensor_{nullptr};
  binary_sensor::BinarySensor *wall_sensor_{nullptr};
  binary_sensor::BinarySensor *left_cliff_sensor_{nullptr};
  binary_sensor::BinarySensor *front_left_cliff_sensor_{nullptr};
  binary_sensor::BinarySensor *front_right_cliff_sensor_{nullptr};
  binary_sensor::BinarySensor *right_cliff_sensor_{nullptr};
  binary_sensor::BinarySensor *virtual_wall_sensor_{nullptr};
  binary_sensor::BinarySensor *side_brush_overcurrent_sensor_{nullptr};
  binary_sensor::BinarySensor *main_brush_overcurrent_sensor_{nullptr};
  binary_sensor::BinarySensor *right_wheel_overcurrent_sensor_{nullptr};
  binary_sensor::BinarySensor *left_wheel_overcurrent_sensor_{nullptr};
  binary_sensor::BinarySensor *clean_button_sensor_{nullptr};
  binary_sensor::BinarySensor *spot_button_sensor_{nullptr};
  binary_sensor::BinarySensor *dock_button_sensor_{nullptr};
  binary_sensor::BinarySensor *minute_button_sensor_{nullptr};
  binary_sensor::BinarySensor *hour_button_sensor_{nullptr};
  binary_sensor::BinarySensor *day_button_sensor_{nullptr};
  binary_sensor::BinarySensor *schedule_button_sensor_{nullptr};
  binary_sensor::BinarySensor *clock_button_sensor_{nullptr};
  binary_sensor::BinarySensor *internal_charger_charging_source_available_sensor_{nullptr};
  binary_sensor::BinarySensor *home_base_charging_source_available_sensor_{nullptr};
  binary_sensor::BinarySensor *song_playing_sensor_{nullptr};
  binary_sensor::BinarySensor *left_light_bumper_sensor_{nullptr};
  binary_sensor::BinarySensor *left_front_light_bumper_sensor_{nullptr};
  binary_sensor::BinarySensor *left_center_light_bumper_sensor_{nullptr};
  binary_sensor::BinarySensor *right_center_light_bumper_sensor_{nullptr};
  binary_sensor::BinarySensor *right_front_light_bumper_sensor_{nullptr};
  binary_sensor::BinarySensor *right_light_bumper_sensor_{nullptr};
  binary_sensor::BinarySensor *toggling_stasis_sensor_{nullptr};
  binary_sensor::BinarySensor *disabled_stasis_sensor_{nullptr};
};

}  // namespace roomba
}  // namespace esphome
