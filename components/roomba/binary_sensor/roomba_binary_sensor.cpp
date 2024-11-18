#include "roomba_binary_sensor.h"

namespace esphome {
namespace roomba {

static const char *const TAG = "roomba.binary_sensor";

void RoombaBinarySensor::update() {}

void RoombaBinarySensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Roomba Binary Sensor:");
  LOG_UPDATE_INTERVAL(this);
  LOG_BINARY_SENSOR("  ", "Vaccum", this->vacuum_sensor_);
}

}  // namespace roomba
}  // namespace esphome