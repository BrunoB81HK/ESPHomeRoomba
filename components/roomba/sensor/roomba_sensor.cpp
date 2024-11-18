#include "roomba_sensor.h"

namespace esphome {
namespace roomba {

static const char *const TAG = "roomba.sensor";

void RoombaSensor::update() {}

void RoombaSensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Roomba Sensor:");
  LOG_UPDATE_INTERVAL(this);
  LOG_SENSOR("  ", "Battery Voltage", this->voltage_sensor_);
  LOG_SENSOR("  ", "Battery Current", this->current_sensor_);
  LOG_SENSOR("  ", "Battery Charge", this->battery_charge_sensor_);
  LOG_SENSOR("  ", "Battery Capacity", this->battery_capacity_sensor_);
  LOG_SENSOR("  ", "Battery", this->battery_percent_sensor_);
  LOG_SENSOR("  ", "Battery Temperature", this->battery_temperature_sensor_);
  LOG_SENSOR("  ", "Drive Speed", this->drive_speed_sensor_);
  LOG_SENSOR("  ", "Main Brush Current", this->main_brush_current_sensor_);
  LOG_SENSOR("  ", "Side Brush Current", this->side_brush_current_sensor_);
}

}  // namespace roomba
}  // namespace esphome