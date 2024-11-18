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

 protected:
  binary_sensor::BinarySensor *vacuum_sensor_{nullptr};
};

}  // namespace roomba
}  // namespace esphome