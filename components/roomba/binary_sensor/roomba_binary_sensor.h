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

  /*
    uint8_t wheel_drop_left{0};            // Binary sensor
    uint8_t wheel_drop_right{0};            // Binary sensor
    uint8_t bumps_left{0};            // Binary sensor
    uint8_t bumps_right{0};            // Binary sensor
    uint8_t wall{0};                             // Binary sensor
    uint8_t cliff_left{0};                       // Binary sensor
    uint8_t cliff_front_left{0};                 // Binary sensor
    uint8_t cliff_front_right{0};                // Binary sensor
    uint8_t cliff_right{0};                      // Binary sensor
    uint8_t virtual_wall{0};                     // Binary sensor
    uint8_t wheel_overcurrents{0};               // Binary sensors
    uint8_t buttons{0};                          // Binary sensors
    uint8_t charging_sources_available{0};       // Binary sensors
    uint8_t song_playing{0};                     // Binary sensor
    uint8_t light_bumper{0};                     // Binary sensors
    int16_t stasis{0};                           // Binary sensors
  */
};

}  // namespace roomba
}  // namespace esphome
