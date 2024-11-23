#include "roomba_binary_sensor.h"

namespace esphome {
namespace roomba {

static const char *const TAG = "roomba.binary_sensor";

inline void update_state(binary_sensor::BinarySensor *sensor, std::function<bool()> func) {
  if (sensor == nullptr)
    return;

  auto new_value = func();
  if (new_value != sensor->state) {
    sensor->publish_state(new_value);
  }
}

void RoombaBinarySensor::update() {
  if (!this->is_ready()) {
    return;
  }

  update_state(this->vacuum_sensor_, [&]() { return false; });
  update_state(this->left_wheel_drop_sensor_, [&]() { return false; });
  update_state(this->right_wheel_drop_sensor_, [&]() { return false; });
  update_state(this->left_bumps_sensor_, [&]() { return false; });
  update_state(this->right_bumps_sensor_, [&]() { return false; });
  update_state(this->wall_sensor_, [&]() { return false; });
  update_state(this->left_cliff_sensor_, [&]() { return false; });
  update_state(this->front_left_cliff_sensor_, [&]() { return false; });
  update_state(this->front_right_cliff_sensor_, [&]() { return false; });
  update_state(this->right_cliff_sensor_, [&]() { return false; });
  update_state(this->virtual_wall_sensor_, [&]() { return false; });
  update_state(this->side_brush_overcurrent_sensor_, [&]() { return false; });
  update_state(this->main_brush_overcurrent_sensor_, [&]() { return false; });
  update_state(this->right_wheel_overcurrent_sensor_, [&]() { return false; });
  update_state(this->left_wheel_overcurrent_sensor_, [&]() { return false; });
  update_state(this->clean_button_sensor_, [&]() { return false; });
  update_state(this->spot_button_sensor_, [&]() { return false; });
  update_state(this->dock_button_sensor_, [&]() { return false; });
  update_state(this->minute_button_sensor_, [&]() { return false; });
  update_state(this->hour_button_sensor_, [&]() { return false; });
  update_state(this->day_button_sensor_, [&]() { return false; });
  update_state(this->schedule_button_sensor_, [&]() { return false; });
  update_state(this->clock_button_sensor_, [&]() { return false; });
  update_state(this->internal_charger_charging_source_available_sensor_, [&]() { return false; });
  update_state(this->home_base_charging_source_available_sensor_, [&]() { return false; });
  update_state(this->song_playing_sensor_, [&]() { return false; });
  update_state(this->left_light_bumper_sensor_, [&]() { return false; });
  update_state(this->left_front_light_bumper_sensor_, [&]() { return false; });
  update_state(this->left_center_light_bumper_sensor_, [&]() { return false; });
  update_state(this->right_center_light_bumper_sensor_, [&]() { return false; });
  update_state(this->right_front_light_bumper_sensor_, [&]() { return false; });
  update_state(this->right_light_bumper_sensor_, [&]() { return false; });
  update_state(this->toggling_stasis_sensor_, [&]() { return false; });
  update_state(this->disabled_stasis_sensor_, [&]() { return false; });
}

void RoombaBinarySensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Roomba Binary Sensor:");
  LOG_UPDATE_INTERVAL(this);
  LOG_BINARY_SENSOR("  ", "Vaccum", this->vacuum_sensor_);
  LOG_BINARY_SENSOR("  ", "Left Wheel Drop", this->left_wheel_drop_sensor_);
  LOG_BINARY_SENSOR("  ", "Right Wheel Drop", this->right_wheel_drop_sensor_);
  LOG_BINARY_SENSOR("  ", "Left Bumps", this->left_bumps_sensor_);
  LOG_BINARY_SENSOR("  ", "Right Bumps", this->right_bumps_sensor_);
  LOG_BINARY_SENSOR("  ", "Wall", this->wall_sensor_);
  LOG_BINARY_SENSOR("  ", "Left Cliff", this->left_cliff_sensor_);
  LOG_BINARY_SENSOR("  ", "Front Left Cliff", this->front_left_cliff_sensor_);
  LOG_BINARY_SENSOR("  ", "Front Right Cliff", this->front_right_cliff_sensor_);
  LOG_BINARY_SENSOR("  ", "Right Cliff", this->right_cliff_sensor_);
  LOG_BINARY_SENSOR("  ", "Virtual Wall", this->virtual_wall_sensor_);
  LOG_BINARY_SENSOR("  ", "Side Brush Overcurrent", this->side_brush_overcurrent_sensor_);
  LOG_BINARY_SENSOR("  ", "Main Brush Overcurrent", this->main_brush_overcurrent_sensor_);
  LOG_BINARY_SENSOR("  ", "Right Wheel Overcurrent", this->right_wheel_overcurrent_sensor_);
  LOG_BINARY_SENSOR("  ", "Left Wheel Overcurrent", this->left_wheel_overcurrent_sensor_);
  LOG_BINARY_SENSOR("  ", "Clean Button", this->clean_button_sensor_);
  LOG_BINARY_SENSOR("  ", "Spot Button", this->spot_button_sensor_);
  LOG_BINARY_SENSOR("  ", "Dock Button", this->dock_button_sensor_);
  LOG_BINARY_SENSOR("  ", "Minute Button", this->minute_button_sensor_);
  LOG_BINARY_SENSOR("  ", "Hour Button", this->hour_button_sensor_);
  LOG_BINARY_SENSOR("  ", "Day Button", this->day_button_sensor_);
  LOG_BINARY_SENSOR("  ", "Schedule Button", this->schedule_button_sensor_);
  LOG_BINARY_SENSOR("  ", "Clock Button", this->clock_button_sensor_);
  LOG_BINARY_SENSOR("  ", "Internal Charger Charging Source Available",
                    this->internal_charger_charging_source_available_sensor_);
  LOG_BINARY_SENSOR("  ", "Home Base Charging Source Available", this->home_base_charging_source_available_sensor_);
  LOG_BINARY_SENSOR("  ", "Song Playing", this->song_playing_sensor_);
  LOG_BINARY_SENSOR("  ", "Left Light Bumper", this->left_light_bumper_sensor_);
  LOG_BINARY_SENSOR("  ", "Left Front Light Bumper", this->left_front_light_bumper_sensor_);
  LOG_BINARY_SENSOR("  ", "Left Center Light Bumper", this->left_center_light_bumper_sensor_);
  LOG_BINARY_SENSOR("  ", "Right Center Light Bumper", this->right_center_light_bumper_sensor_);
  LOG_BINARY_SENSOR("  ", "Right Front Light Bumper", this->right_front_light_bumper_sensor_);
  LOG_BINARY_SENSOR("  ", "Right Light Bumper", this->right_light_bumper_sensor_);
  LOG_BINARY_SENSOR("  ", "Toggling Stasis", this->toggling_stasis_sensor_);
  LOG_BINARY_SENSOR("  ", "Disabled Stasis", this->disabled_stasis_sensor_);
}

}  // namespace roomba
}  // namespace esphome
