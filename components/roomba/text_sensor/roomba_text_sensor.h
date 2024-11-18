#pragma once

#include "esphome/components/text_sensor/text_sensor.h"
#include "../roomba.h"

namespace esphome {
namespace roomba {

class RoombaTextSensor : public PollingComponent, public RoombaClient {
 public:
  void update() override;
  void dump_config() override;

  void set_charging_sensor(text_sensor::TextSensor *text_sensor) { this->charging_sensor_ = text_sensor; }
  void set_activity_sensor(text_sensor::TextSensor *text_sensor) { this->activity_sensor_ = text_sensor; }
  void set_oi_mode_sensor(text_sensor::TextSensor *text_sensor) { this->oi_mode_sensor_ = text_sensor; }

 protected:
  text_sensor::TextSensor *charging_sensor_{nullptr};
  text_sensor::TextSensor *activity_sensor_{nullptr};
  text_sensor::TextSensor *oi_mode_sensor_{nullptr};
};

}  // namespace roomba
}  // namespace esphome