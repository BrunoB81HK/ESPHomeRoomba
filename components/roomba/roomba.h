#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace roomba {

enum class RoombaSensorCode : uint8_t {
  _7to26 = 0,                     // 00
  _7to16 = 1,                     // 01
  _17to20 = 2,                    // 02
  _21to26 = 3,                    // 03
  _27to34 = 4,                    // 04
  _35to42 = 5,                    // 05
  _7to42 = 6,                     // 06
  BumpsAndWheelDrops = 7,         // 07
  Wall = 8,                       // 08
  CliffLeft = 9,                  // 09
  CliffFrontLeft = 10,            // 0A
  CliffFrontRight = 11,           // 0B
  CliffRight = 12,                // 0C
  VirtualWall = 13,               // 0D
  Overcurrents = 14,              // 0E
  Unused1 = 15,                   // 0F
  Unused2 = 16,                   // 10
  IRByte = 17,                    // 11
  Buttons = 18,                   // 12
  Distance = 19,                  // 13
  Angle = 20,                     // 14
  ChargingState = 21,             // 15
  Voltage = 22,                   // 16
  Current = 23,                   // 17
  BatteryTemperature = 24,        // 18
  BatteryCharge = 25,             // 19
  BatteryCapacity = 26,           // 1A
  WallSignal = 27,                // 1B
  CliffLeftSignal = 28,           // 1C
  CliffFrontLeftSignal = 29,      // 1D
  CliffFrontRightSignal = 30,     // 1E
  CliffRightSignal = 31,          // 1F
  UserDigitalInputs = 32,         // 20
  UserAnalogInput = 33,           // 21
  ChargingSourcesAvailable = 34,  // 22
  OIMode = 35,                    // 23
  SongNumber = 36,                // 24
  SongPlaying = 37,               // 25
  NumberOfStreamPackets = 38,     // 26
  Velocity = 39,                  // 27
  Radius = 40,                    // 28
  RightVelocity = 41,             // 29
  LeftVelocity = 42,              // 2A
  MainBrushCurrent = 56,          // 38
  SideBrushCurrent = 57,          // 39
};

enum class RoombaChargeState : uint8_t {
  NotCharging = 0,
  ReconditioningCharging = 1,
  FullCharging = 2,
  TrickleCharging = 3,
  Waiting = 4,
  Fault = 5,
};

enum class RoombaCommands : uint8_t {
  Reset = 7,          // 07
  Start = 128,        // 80
  Stop = 173,         // AD
  Safe = 131,         // 83
  Full = 132,         // 84
  Clean = 135,        // 87
  Spot = 134,         // 86
  Dock = 143,         // 8F
  Power = 133,        // 85
  Drive = 137,        // 89
  Motors = 138,       // 8A
  LEDAscii = 164,     // A4
  Song = 140,         // 8C
  Play = 141,         // 8D
  SensorsList = 149,  // 95
};

class RoombaComponent : public PollingComponent, public CustomAPIDevice, public UARTDevice {
 public:
  void setup() override;
  void update() override;
  void dump_config() override;

  void set_brc_pin(uint8_t pin) { this->brc_pin_ = brc_pin; }
  void set_lazy_650(bool enabled) { this->lazy_650_enabled_ = enabled; }
  void set_uart(uart::UARTComponent *uart);

  void send_command(std::string command) { on_command(command); }

 private:
  uint8_t brc_pin_{0};
  bool lazy_650_enabled_{false};
  uart::UARTComponent *uart_{nullptr};

  uint8_t charging_state_;
  int last_wakeup_time_ = 0;
  bool was_cleaning_ = false;
  bool was_docked_ = false;
  int16_t speed_ = 0;
};

class RoombaClient {
 public:
  void set_roomba(RoombaComponent *roomba) { this->roomba_ = roomba; }

 protected:
  RoombaComponent *roomba_;
};

}  // namespace roomba
}  // namespace esphome
