#include "roomba_text_sensor.h"

namespace esphome {
namespace roomba {

static const char *const TAG = "roomba.text_sensor";

inline std::string_view to_string(RoombaActivity activity) {
  switch (activity) {
    case RoombaActivity::Docked:
      return "Docked";
    case RoombaActivity::Charging:
      return "Charging";
    case RoombaActivity::Cleaning:
      return "Cleaning";
    case RoombaActivity::Lost:
      return "Lost";
    default:
      return "Unknown Activity";
  }
}

inline std::string_view to_string(RoombaChargeState charge_state) {
  switch (charge_state) {
    case RoombaChargeState::NotCharging:
      return "NotCharging";
    case RoombaChargeState::ReconditioningCharging:
      return "ReconditioningCharging";
    case RoombaChargeState::FullCharging:
      return "FullCharging";
    case RoombaChargeState::TrickleCharging:
      return "TrickleCharging";
    case RoombaChargeState::Waiting:
      return "Waiting";
    case RoombaChargeState::Fault:
      return "Fault";
    default:
      return "Unknown Charging State";
  }
}

inline std::string_view to_string(RoombaOIMode oi_mode) {
  switch (oi_mode) {
    case RoombaOIMode::Off:
      return "Off";
    case RoombaOIMode::Passive:
      return "Passive";
    case RoombaOIMode::Safe:
      return "Safe";
    case RoombaOIMode::Full:
      return "Full";
    default:
      return "Unknown OI Mode";
  }
}

void RoombaTextSensor::update() {
  if (this->activity_sensor_ != nullptr) {
    auto activity = to_string(this->roomba_->activity_);

    if (activity != this->activity_sensor_->state) {
      this->activity_sensor_->publish_state(activity);
    }
  }

  if (this->charging_state_sensor_ != nullptr) {
    auto charging_state = to_string(static_cast<RoombaChargeState>(this->roomba_->sensors_values_.charging_state));

    if (charging_state != this->charging_state_sensor_->state) {
      this->charging_state_sensor_->publish_state(charging_state);
    }
  }

  if (this->oi_mode_sensor_ != nullptr) {
    auto oi_mode = to_string(static_cast<RoombaOIMode>(this->roomba_->sensors_values_.oi_mode));

    if (oi_mode != this->oi_mode_sensor_->state) {
      this->oi_mode_sensor_->publish_state(oi_mode);
    }
  }
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
