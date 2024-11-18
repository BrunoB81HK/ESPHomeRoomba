#include "roomba.h"

#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome {
namespace roomba {

static const char *const TAG = "roomba";

void RoombaComponent::setup() {
  if (this->lazy_650_enabled_) {
    // High-impedence on the BRC_PIN
    // see
    // https://github.com/johnboiles/esp-roomba-mqtt/commit/fa9af14376f740f366a9ecf4cb59dec2419deeb0#diff-34d21af3c614ea3cee120df276c9c4ae95053830d7f1d3deaf009a4625409ad2R140
    pinMode(this->brc_pin_, INPUT);
  } else {
    pinMode(this->brc_pin_, OUTPUT);
    digitalWrite(this->brc_pin_, HIGH);
  }
}

void RoombaComponent::update() {
  if (this->lazy_650_enabled_) {
    long now = millis();
    // Wakeup the roomba at fixed intervals
    if (now - lastWakeupTime > 50000) {
      ESP_LOGD("roomba", "Time to wakeup");
      lastWakeupTime = now;
      if (!wasCleaning) {
        if (wasDocked) {
          wake_on_dock();
        } else {
          brc_wakeup();
        }
      } else {
        brc_wakeup();
      }
    }
  }

  uint8_t charging;
  uint16_t voltage;
  int16_t current;
  uint16_t batteryCharge;
  uint16_t batteryCapacity;
  int16_t batteryTemperature;
  int16_t mainBrushCurrent;
  int16_t sideBrushCurrent;

  flush();

  uint8_t sensors[] = {
      SensorChargingState,      SensorVoltage, SensorCurrent,          SensorBatteryCharge,    SensorBatteryCapacity,
      SensorBatteryTemperature, SensorOIMode,  SensorMainBrushCurrent, SensorSideBrushCurrent,
  };

  uint8_t values[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  bool success = getSensorsList(sensors, sizeof(sensors), values, sizeof(values));
  if (!success) {
    ESP_LOGD("roomba", "Could not get sensor values from serial");
    return;
  }

  charging = values[0];
  voltage = values[1] * 256 + values[2];
  current = values[3] * 256 + values[4];
  batteryCharge = values[5] * 256 + values[6];
  batteryCapacity = values[7] * 256 + values[8];
  batteryTemperature = values[9];
  std::string oiMode = get_oimode(values[10]);
  mainBrushCurrent = values[11] * 256 + values[12];
  sideBrushCurrent = values[13] * 256 + values[14];

  std::string activity = get_activity(charging, current);
  wasCleaning = activity == "Cleaning";
  wasDocked = activity == "Docked";

  float voltageData = 0.001 * roundf(voltage * 100) / 100;
  if (this->voltageSensor->state != voltageData) {
    this->voltageSensor->publish_state(voltageData);
  }

  float currentData = 0.001 * roundf(current * 100) / 100;
  if (this->currentSensor->state != currentData) {
    this->currentSensor->publish_state(currentData);
  }

  float charge = 0.001 * roundf(batteryCharge * 100) / 100;
  if (this->batteryChargeSensor->state != charge) {
    this->batteryChargeSensor->publish_state(charge);
  }

  float capacity = 0.001 * roundf(batteryCapacity * 100) / 100;
  if (this->batteryCapacitySensor->state != capacity) {
    this->batteryCapacitySensor->publish_state(capacity);
  }

  float battery_level = 100.0 * ((1.0 * charge) / (1.0 * capacity));
  if (this->batteryPercentSensor->state != battery_level) {
    this->batteryPercentSensor->publish_state(battery_level);
  }

  if (this->batteryTemperatureSensor->state != batteryTemperature) {
    this->batteryTemperatureSensor->publish_state(batteryTemperature);
  }

  if (this->chargingState != charging) {
    this->chargingState = charging;
    this->chargingSensor->publish_state(ToString(charging));
  }

  if (activity.compare(this->activitySensor->state) != 0) {
    this->activitySensor->publish_state(activity);
  }

  if (this->driveSpeedSensor->state != this->speed) {
    this->driveSpeedSensor->publish_state(this->speed);
  }

  if (oiMode.compare(this->oiModeSensor->state) != 0) {
    this->oiModeSensor->publish_state(oiMode);
  }

  float mainBrushCurrentData = 0.001 * (mainBrushCurrent * 100) / 100;
  if (this->mainBrushCurrentSensor->state != mainBrushCurrentData) {
    this->mainBrushCurrentSensor->publish_state(mainBrushCurrentData);
  }

  float sideBrushCurrentData = 0.001 * (sideBrushCurrent * 100) / 100;
  if (this->sideBrushCurrentSensor->state != sideBrushCurrentData) {
    this->sideBrushCurrentSensor->publish_state(sideBrushCurrentData);
  }
}

void RoombaComponent::dump_config() {
  LOG_BINARY_SENSOR("", "Roomba Component", this);
  LOG_SENSOR("  ", "Sensor", this->sensor_);
  ESP_LOGCONFIG(TAG, "  Upper threshold: %.11f", this->upper_threshold_);
  ESP_LOGCONFIG(TAG, "  Lower threshold: %.11f", this->lower_threshold_);
}

}  // namespace roomba
}  // namespace esphome