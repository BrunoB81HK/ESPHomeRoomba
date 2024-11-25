#pragma once

#include <cstdint>

namespace esphome {
namespace roomba {

struct __attribute__((packed)) SensorsValues {
  uint8_t bumps_and_wheel_drops{0};            // #7  - Binary sensors (x4)
  uint8_t wall{0};                             // #8  - Binary sensor
  uint8_t cliff_left{0};                       // #9  - Binary sensor
  uint8_t cliff_front_left{0};                 // #10 - Binary sensor
  uint8_t cliff_front_right{0};                // #11 - Binary sensor
  uint8_t cliff_right{0};                      // #12 - Binary sensor
  uint8_t virtual_wall{0};                     // #13 - Binary sensor
  uint8_t wheel_overcurrents{0};               // #14 - Binary sensors (x4)
  uint8_t dirt_detect{0};                      // #15 - Sensor
  uint8_t unused1{0};                          // #16
  uint8_t ir_byte_omni{0};                     // #17 - Sensor
  uint8_t buttons{0};                          // #18 - Binary sensors (x8)
  int16_t distance{0};                         // #19 - Sensor
  int16_t angle{0};                            // #20 - Sensor
  uint8_t charging_state{0};                   // #21 - Text Sensor
  uint16_t voltage{0};                         // #22 - Sensor
  int16_t current{0};                          // #23 - Sensor
  int8_t battery_temperature{0};               // #24 - Sensor
  uint16_t battery_charge{0};                  // #25 - Sensor
  uint16_t battery_capacity{0};                // #26 - Sensor
  uint16_t wall_signal{0};                     // #27 - Sensor ** Deprecated, use #51 **
  uint16_t cliff_left_signal{0};               // #28 - Sensor
  uint16_t cliff_front_left_signal{0};         // #29 - Sensor
  uint16_t cliff_front_right_signal{0};        // #30 - Sensor
  uint16_t cliff_right_signal{0};              // #31 - Sensor
  uint16_t unused2{0};                         // #32/#33   ** Should be uint12_t (3 bytes) **
  uint8_t unused3{0};                          // #33   ** Should be uint12_t (3 bytes) **
  uint8_t charging_sources_available{0};       // #34 - Binary sensors (x2)
  uint8_t oi_mode{0};                          // #35 - Text Sensor
  uint8_t song_number{0};                      // #36 - Sensor
  uint8_t song_playing{0};                     // #37 - Binary sensor
  uint8_t number_of_stream_packets{0};         // #38 - Sensor
  int16_t requested_velocity{0};               // #39 - Sensor
  int16_t requested_radius{0};                 // #40 - Sensor
  int16_t requested_right_velocity{0};         // #41 - Sensor
  int16_t requested_left_velocity{0};          // #42 - Sensor
  int16_t left_encoder_counts{0};              // #43 - Sensor
  int16_t right_encoder_counts{0};             // #44 - Sensor
  uint8_t light_bumper{0};                     // #45 - Binary sensors (x6)
  uint16_t light_bump_left_signal{0};          // #46 - Sensor
  uint16_t light_bump_front_left_signal{0};    // #47 - Sensor
  uint16_t light_bump_center_left_signal{0};   // #48 - Sensor
  uint16_t light_bump_center_right_signal{0};  // #49 - Sensor
  uint16_t light_bump_front_right_signal{0};   // #50 - Sensor
  uint16_t light_bump_right_signal{0};         // #51 - Sensor
  uint8_t ir_byte_left{0};                     // #52 - Sensor
  uint8_t ir_byte_right{0};                    // #53 - Sensor
  int16_t left_motor_current{0};               // #54 - Sensor
  int16_t right_motor_current{0};              // #55 - Sensor
  int16_t main_brush_current{0};               // #56 - Sensor
  int16_t side_brush_current{0};               // #57 - Sensor
  int8_t stasis{0};                            // #58 - Binary sensors (x2)
};

}  // namespace roomba
}  // namespace esphome
