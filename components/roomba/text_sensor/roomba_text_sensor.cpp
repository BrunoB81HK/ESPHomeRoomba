#include "roomba_text_sensor.h"

namespace esphome {
namespace roomba {

static const char *const TAG = "roomba.text_sensor";

void RoombaTextSensor::update() {}

void RoombaTextSensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Roomba Text Sensor:");
  LOG_UPDATE_INTERVAL(this);
  LOG_TEXT_SENSOR("  ", "Charging State", this->charging_sensor_);
  LOG_TEXT_SENSOR("  ", "Activity", this->activity_sensor_);
  LOG_TEXT_SENSOR("  ", "OI Mode", this->oi_mode_sensor_);
}

}  // namespace roomba
}  // namespace esphome