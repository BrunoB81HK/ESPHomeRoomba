#include "roomba_text_sensor.h"

#include <functional>

namespace esphome {
namespace roomba {

static const char *const TAG = "roomba.text_sensor";

inline std::string to_string(Activity activity) {
  switch (activity) {
    case Activity::Docked:
      return "Docked";
    case Activity::Charging:
      return "Charging";
    case Activity::Cleaning:
      return "Cleaning";
    case Activity::Lost:
      return "Lost";
    default:
      return "Unknown";
  }
}

inline std::string to_string(ChargeState charge_state) {
  switch (charge_state) {
    case ChargeState::NotCharging:
      return "NotCharging";
    case ChargeState::ReconditioningCharging:
      return "ReconditioningCharging";
    case ChargeState::FullCharging:
      return "FullCharging";
    case ChargeState::TrickleCharging:
      return "TrickleCharging";
    case ChargeState::Waiting:
      return "Waiting";
    case ChargeState::Fault:
      return "Fault";
    default:
      return "Unknown ";
  }
}

inline std::string to_string(OIMode oi_mode) {
  switch (oi_mode) {
    case OIMode::Off:
      return "Off";
    case OIMode::Passive:
      return "Passive";
    case OIMode::Safe:
      return "Safe";
    case OIMode::Full:
      return "Full";
    default:
      return "Unknown OI Mode";
  }
}

inline void update_state(text_sensor::TextSensor *sensor, std::function<std::string()> func) {
  if (sensor == nullptr)
    return;

  auto new_value = func();
  if (new_value != sensor->state) {
    sensor->publish_state(new_value);
  }
}

void RoombaTextSensor::update() {
  if (!this->is_ready()) {
    return;
  }

  update_state(this->activity_sensor_, [&]() { return to_string(this->roomba_->activity_); });
  update_state(this->charging_state_sensor_,
               [&]() { return to_string(static_cast<ChargeState>(this->roomba_->sensors_values_.charging_state)); });
  update_state(this->oi_mode_sensor_,
               [&]() { return to_string(static_cast<OIMode>(this->roomba_->sensors_values_.oi_mode)); });
}

void RoombaTextSensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Roomba Text Sensor:");
  LOG_UPDATE_INTERVAL(this);
  LOG_TEXT_SENSOR("  ", "Activity: ", this->activity_sensor_);
  LOG_TEXT_SENSOR("  ", "Charging State: ", this->charging_state_sensor_);
  LOG_TEXT_SENSOR("  ", "OI Mode: ", this->oi_mode_sensor_);
}

}  // namespace roomba
}  // namespace esphome
