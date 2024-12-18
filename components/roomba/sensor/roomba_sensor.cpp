#include "roomba_sensor.h"

namespace esphome {
namespace roomba {

static const char *const TAG = "roomba.sensor";

void RoombaSensor::update() {
  if (!this->is_ready()) {
    return;
  }

  this->update_state(this->dirt_detect_sensor_, [&]() { return this->roomba_->sensors_values_.dirt_detect; });
  this->update_state(this->ir_byte_omni_sensor_, [&]() { return this->roomba_->sensors_values_.ir_byte_omni; });
  this->update_state(this->distance_sensor_, [&]() { return this->roomba_->sensors_values_.distance; });
  this->update_state(this->angle_sensor_, [&]() { return this->roomba_->sensors_values_.angle; });
  this->update_state(this->voltage_sensor_, [&]() { return this->roomba_->sensors_values_.voltage; });
  this->update_state(this->current_sensor_, [&]() { return this->roomba_->sensors_values_.current; });
  this->update_state(this->battery_temperature_sensor_,
                     [&]() { return this->roomba_->sensors_values_.battery_temperature; });
  this->update_state(this->battery_charge_sensor_, [&]() { return this->roomba_->sensors_values_.battery_charge; });
  this->update_state(this->battery_capacity_sensor_, [&]() { return this->roomba_->sensors_values_.battery_capacity; });
  this->update_state(this->battery_percent_sensor_, [&]() {
    return 100.0f * this->roomba_->sensors_values_.battery_charge / this->roomba_->sensors_values_.battery_capacity;
  });
  this->update_state(this->wall_signal_sensor_, [&]() { return this->roomba_->sensors_values_.wall_signal; });
  this->update_state(this->cliff_left_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.cliff_left_signal; });
  this->update_state(this->cliff_front_left_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.cliff_front_left_signal; });
  this->update_state(this->cliff_front_right_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.cliff_front_right_signal; });
  this->update_state(this->cliff_right_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.cliff_right_signal; });
  this->update_state(this->song_number_sensor_, [&]() { return this->roomba_->sensors_values_.song_number; });
  this->update_state(this->number_of_stream_packets_sensor_,
                     [&]() { return this->roomba_->sensors_values_.number_of_stream_packets; });
  this->update_state(this->requested_velocity_sensor_,
                     [&]() { return this->roomba_->sensors_values_.requested_velocity; });
  this->update_state(this->requested_radius_sensor_, [&]() { return this->roomba_->sensors_values_.requested_radius; });
  this->update_state(this->requested_right_velocity_sensor_,
                     [&]() { return this->roomba_->sensors_values_.requested_right_velocity; });
  this->update_state(this->requested_left_velocity_sensor_,
                     [&]() { return this->roomba_->sensors_values_.requested_left_velocity; });
  this->update_state(this->left_encoder_counts_sensor_,
                     [&]() { return this->roomba_->sensors_values_.left_encoder_counts; });
  this->update_state(this->right_encoder_counts_sensor_,
                     [&]() { return this->roomba_->sensors_values_.right_encoder_counts; });
  this->update_state(this->light_bump_left_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.light_bump_left_signal; });
  this->update_state(this->light_bump_front_left_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.light_bump_front_left_signal; });
  this->update_state(this->light_bump_center_left_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.light_bump_center_left_signal; });
  this->update_state(this->light_bump_center_right_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.light_bump_center_right_signal; });
  this->update_state(this->light_bump_front_right_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.light_bump_front_right_signal; });
  this->update_state(this->light_bump_right_signal_sensor_,
                     [&]() { return this->roomba_->sensors_values_.light_bump_right_signal; });
  this->update_state(this->ir_byte_left_sensor_, [&]() { return this->roomba_->sensors_values_.ir_byte_left; });
  this->update_state(this->ir_byte_right_sensor_, [&]() { return this->roomba_->sensors_values_.ir_byte_right; });
  this->update_state(this->left_motor_current_sensor_,
                     [&]() { return this->roomba_->sensors_values_.left_motor_current; });
  this->update_state(this->right_motor_current_sensor_,
                     [&]() { return this->roomba_->sensors_values_.right_motor_current; });
  this->update_state(this->main_brush_current_sensor_,
                     [&]() { return this->roomba_->sensors_values_.main_brush_current; });
  this->update_state(this->side_brush_current_sensor_,
                     [&]() { return this->roomba_->sensors_values_.side_brush_current; });
}

void RoombaSensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Roomba Sensor:");
  LOG_UPDATE_INTERVAL(this);
  LOG_SENSOR("  ", "Dirt Detect: ", this->dirt_detect_sensor_);
  LOG_SENSOR("  ", "IR Byte Omni: ", this->ir_byte_omni_sensor_);
  LOG_SENSOR("  ", "Distance: ", this->distance_sensor_);
  LOG_SENSOR("  ", "Angle: ", this->angle_sensor_);
  LOG_SENSOR("  ", "Voltage: ", this->voltage_sensor_);
  LOG_SENSOR("  ", "Current: ", this->current_sensor_);
  LOG_SENSOR("  ", "Battery Temperature: ", this->battery_temperature_sensor_);
  LOG_SENSOR("  ", "Battery Charge: ", this->battery_charge_sensor_);
  LOG_SENSOR("  ", "Battery Capacity: ", this->battery_capacity_sensor_);
  LOG_SENSOR("  ", "Battery Percent: ", this->battery_percent_sensor_);
  LOG_SENSOR("  ", "Wall Signal: ", this->wall_signal_sensor_);
  LOG_SENSOR("  ", "Cliff Left Signal: ", this->cliff_left_signal_sensor_);
  LOG_SENSOR("  ", "Cliff Front Left Signal: ", this->cliff_front_left_signal_sensor_);
  LOG_SENSOR("  ", "Cliff Front Right Signal: ", this->cliff_front_right_signal_sensor_);
  LOG_SENSOR("  ", "Cliff Right Signal: ", this->cliff_right_signal_sensor_);
  LOG_SENSOR("  ", "Song Number: ", this->song_number_sensor_);
  LOG_SENSOR("  ", "Number of Stream Packets: ", this->number_of_stream_packets_sensor_);
  LOG_SENSOR("  ", "Requested Velocity: ", this->requested_velocity_sensor_);
  LOG_SENSOR("  ", "Requested Radius: ", this->requested_radius_sensor_);
  LOG_SENSOR("  ", "Requested Right Velocity: ", this->requested_right_velocity_sensor_);
  LOG_SENSOR("  ", "Requested Left Velocity: ", this->requested_left_velocity_sensor_);
  LOG_SENSOR("  ", "Left Encoder Counts: ", this->left_encoder_counts_sensor_);
  LOG_SENSOR("  ", "Right Encoder Counts: ", this->right_encoder_counts_sensor_);
  LOG_SENSOR("  ", "Light Bump Left Signal: ", this->light_bump_left_signal_sensor_);
  LOG_SENSOR("  ", "Light Bump Front Left Signal: ", this->light_bump_front_left_signal_sensor_);
  LOG_SENSOR("  ", "Light Bump Center Left Signal: ", this->light_bump_center_left_signal_sensor_);
  LOG_SENSOR("  ", "Light Bump Center Right Signal: ", this->light_bump_center_right_signal_sensor_);
  LOG_SENSOR("  ", "Light Bump Front Right Signal: ", this->light_bump_front_right_signal_sensor_);
  LOG_SENSOR("  ", "Light Bump Right Signal: ", this->light_bump_right_signal_sensor_);
  LOG_SENSOR("  ", "IR Byte Left: ", this->ir_byte_left_sensor_);
  LOG_SENSOR("  ", "IR Byte Right: ", this->ir_byte_right_sensor_);
  LOG_SENSOR("  ", "Left Motor Current: ", this->left_motor_current_sensor_);
  LOG_SENSOR("  ", "Right Motor Current: ", this->right_motor_current_sensor_);
  LOG_SENSOR("  ", "Main Brush Current: ", this->main_brush_current_sensor_);
  LOG_SENSOR("  ", "Side Brush Current: ", this->side_brush_current_sensor_);
}

}  // namespace roomba
}  // namespace esphome
