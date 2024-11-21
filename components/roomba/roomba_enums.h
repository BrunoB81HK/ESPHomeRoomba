#pragma once

#include <cstdint>
#include <type_traits>

namespace esphome {
namespace roomba {

template<typename Enum, typename std::enable_if<std::is_enum<Enum>::value, bool>::type = true>
constexpr typename std::underlying_type<Enum>::type operator+(Enum e) noexcept {
  using underlying = typename std::underlying_type<Enum>::type;
  return static_cast<underlying>(e);
}

enum class Command : uint8_t {
  // Getting started
  Reset = 7,
  Start = 128,
  Stop = 173,
  Baud = 129,
  // Mode
  Safe = 131,
  Full = 132,
  // Cleaning
  Clean = 135,
  Max = 136,
  Spot = 134,
  SeekDock = 143,
  Power = 133,
  Schedule = 167,
  SetDayTime = 168,
  // Actuator
  Drive = 137,
  DriveDirect = 145,
  DrivePWM = 146,
  Motors = 138,
  MotorsPWM = 144,
  LEDs = 139,
  LEDsScheduling = 162,
  LEDsDigitRaw = 163,
  LEDsDigitASCII = 164,
  Buttons = 165,
  Song = 140,
  Play = 141,
  // Input
  Sensors = 142,
  QueryList = 149,
  Stream = 148,
  StreamPauseResume = 150,
  Control = 130,
};

enum class Baud : uint8_t {
  BPS300 = 0,      // 300 BPS
  BPS600 = 1,      // 600 BPS
  BPS1200 = 2,     // 1200 BPS
  BPS2400 = 3,     // 2400 BPS
  BPS4800 = 4,     // 4800 BPS
  BPS9600 = 5,     // 9600 BPS
  BPS14400 = 6,    // 14400 BPS
  BPS19200 = 7,    // 19200 BPS
  BPS28800 = 8,    // 28800 BPS
  BPS38400 = 9,    // 38400 BPS
  BPS57600 = 10,   // 57600 BPS
  BPS115200 = 11,  // 115200 BPS
};

enum class Weekday : uint8_t {
  Sunday = 0,
  Monday = 1,
  Tuesday = 2,
  Wednesday = 3,
  Thursday = 4,
  Friday = 5,
  Saturday = 6,
};

enum class SongNote : uint8_t {
  NoteG1 = 31,    // 49.0 Hz
  NoteG1s = 32,   // 51.0 Hz
  NoteA1 = 33,    // 55.0 Hz
  NoteA1s = 34,   // 58.3 Hz
  NoteB1 = 35,    // 61.7 Hz
  NoteC2 = 36,    // 65.4 Hz
  NoteC2s = 37,   // 69.3 Hz
  NoteD2 = 38,    // 73.4 Hz
  NoteD2s = 39,   // 77.8 Hz
  NoteE2 = 40,    // 82.4 Hz
  NoteF2 = 41,    // 87.3 Hz
  NoteF2s = 42,   // 92.5 Hz
  NoteG2 = 43,    // 98.0 Hz
  NoteG2s = 44,   // 103.8 Hz
  NoteA2 = 45,    // 110.0 Hz
  NoteA2s = 46,   // 116.5 Hz
  NoteB2 = 47,    // 123.5 Hz
  NoteC3 = 48,    // 130.8 Hz
  NoteC3s = 49,   // 138.6 Hz
  NoteD3 = 50,    // 146.8 Hz
  NoteD3s = 51,   // 155.6 Hz
  NoteE3 = 52,    // 164.8 Hz
  NoteF3 = 53,    // 174.6 Hz
  NoteF3s = 54,   // 185.0 Hz
  NoteG3 = 55,    // 196.0 Hz
  NoteG3s = 56,   // 207.7 Hz
  NoteA3 = 57,    // 220.0 Hz
  NoteA3s = 58,   // 233.1 Hz
  NoteB3 = 59,    // 246.9 Hz
  NoteC4 = 60,    // 261.6 Hz
  NoteC4s = 61,   // 277.2 Hz
  NoteD4 = 62,    // 293.7 Hz
  NoteD4s = 63,   // 311.1 Hz
  NoteE4 = 64,    // 329.6 Hz
  NoteF4 = 65,    // 349.2 Hz
  NoteF4s = 66,   // 370.0 Hz
  NoteG4 = 67,    // 392.0 Hz
  NoteG4s = 68,   // 415.3 Hz
  NoteA4 = 69,    // 440.0 Hz
  NoteA4s = 70,   // 466.2 Hz
  NoteB4 = 71,    // 493.9 Hz
  NoteC5 = 72,    // 523.3 Hz
  NoteC5s = 73,   // 554.4 Hz
  NoteD5 = 74,    // 587.3 Hz
  NoteD5s = 75,   // 622.3 Hz
  NoteE5 = 76,    // 659.3 Hz
  NoteF5 = 77,    // 698.5 Hz
  NoteF5s = 78,   // 740.0 Hz
  NoteG5 = 79,    // 784.0 Hz
  NoteG5s = 80,   // 830.6 Hz
  NoteA5 = 81,    // 880.0 Hz
  NoteA5s = 82,   // 932.3 Hz
  NoteB5 = 83,    // 987.8 Hz
  NoteC6 = 84,    // 1046.5 Hz
  NoteC6s = 85,   // 1108.7 Hz
  NoteD6 = 86,    // 1174.7 Hz
  NoteD6s = 87,   // 1244.5 Hz
  NoteE6 = 88,    // 1318.5 Hz
  NoteF6 = 89,    // 1396.9 Hz
  NoteF6s = 90,   // 1480.0 Hz
  NoteG6 = 91,    // 1568.0 Hz
  NoteG6s = 92,   // 1661.2 Hz
  NoteA6 = 93,    // 1760.0 Hz
  NoteA6s = 94,   // 1864.7 Hz
  NoteB6 = 95,    // 1975.5 Hz
  NoteC7 = 96,    // 2093.0 Hz
  NoteC7s = 97,   // 2217.5 Hz
  NoteD7 = 98,    // 2349.3 Hz
  NoteD7s = 99,   // 2489.0 Hz
  NoteE7 = 100,   // 2637.0 Hz
  NoteF7 = 101,   // 2793.8 Hz
  NoteF7s = 102,  // 2960.0 Hz
  NoteG7 = 103,   // 3136.0 Hz
  NoteG7s = 104,  // 3322.4 Hz
  NoteA7 = 105,   // 3520.0 Hz
  NoteA7s = 106,  // 3729.3 Hz
  NoteB7 = 107,   // 3951.1 Hz
  NoteC8 = 108,   // 4186.0 Hz
  NoteC8s = 109,  // 4434.9 Hz
  NoteD8 = 110,   // 4698.6 Hz
  NoteD8s = 111,  // 4978.0 Hz
  NoteE8 = 112,   // 5274.0 Hz
  NoteF8 = 113,   // 5587.7 Hz
  NoteF8s = 114,  // 5919.9 Hz
  NoteG8 = 115,   // 6271.9 Hz
  NoteG8s = 116,  // 6644.9 Hz
  NoteA8 = 117,   // 7040.0 Hz
  NoteA8s = 118,  // 7458.6 Hz
  NoteB8 = 119,   // 7902.1 Hz
  NoteC9 = 120,   // 8372.0 Hz
  NoteC9s = 121,  // 8869.8 Hz
  NoteD9 = 122,   // 9397.3 Hz
  NoteD9s = 123,  // 9956.1 Hz
  NoteE9 = 124,   // 10548.1 Hz
  NoteF9 = 125,   // 11175.3 Hz
  NoteF9s = 126,  // 11839.8 Hz
  NoteG9 = 127,   // 12543.9 Hz
};

enum class SensorPackets : uint8_t {
  Group7to26 = 0,                   // Size: 26 packets
  Group7to16 = 1,                   // Size: 10 packets
  Group17to20 = 2,                  // Size: 6 packets
  Group21to26 = 3,                  // Size: 10 packets
  Group27to34 = 4,                  // Size: 14 packets
  Group35to42 = 5,                  // Size: 12 packets
  Group7to42 = 6,                   // Size: 52 packets
  Group7to58 = 100,                 // Size: 80 packets
  Group43to58 = 101,                // Size: 28 packets
  Group46to52 = 106,                // Size: 12 packets
  Group54to58 = 107,                // Size: 9 packets
  BumpsAndWheelDrops = 7,           // 1 byte(s), unsigned
  Wall = 8,                         // 1 byte(s), unsigned
  CliffLeft = 9,                    // 1 byte(s), unsigned
  CliffFrontLeft = 10,              // 1 byte(s), unsigned
  CliffFrontRight = 11,             // 1 byte(s), unsigned
  CliffRight = 12,                  // 1 byte(s), unsigned
  VirtualWall = 13,                 // 1 byte(s), unsigned
  WheelOvercurrents = 14,           // 1 byte(s), unsigned
  DirtDetect = 15,                  // 1 byte(s), unsigned
  Unused1 = 16,                     // 1 byte(s)
  IRByteOmni = 17,                  // 1 byte(s), unsigned
  IRByteLeft = 52,                  // 1 byte(s), unsigned
  IRByteRight = 53,                 // 1 byte(s), unsigned
  Buttons = 18,                     // 1 byte(s), unsigned
  Distance = 19,                    // 2 byte(s), signed
  Angle = 20,                       // 2 byte(s), signed
  ChargingState = 21,               // 1 byte(s), unsigned
  Voltage = 22,                     // 2 byte(s), unsigned, mV
  Current = 23,                     // 2 byte(s), signed, mA
  BatteryTemperature = 24,          // 1 byte(s), signed, C
  BatteryCharge = 25,               // 2 byte(s), unsigned, mAh
  BatteryCapacity = 26,             // 2 byte(s), unsigned, mAh
  WallSignal = 27,                  // 2 byte(s), unsigned
  CliffLeftSignal = 28,             // 2 byte(s), unsigned
  CliffFrontLeftSignal = 29,        // 2 byte(s), unsigned
  CliffFrontRightSignal = 30,       // 2 byte(s), unsigned
  CliffRightSignal = 31,            // 2 byte(s), unsigned
  Unused2 = 32,                     // 3 byte(s)
  Unused3 = 33,                     // 3 byte(s)
  ChargingSourcesAvailable = 34,    // 1 byte(s), unsigned
  OIMode = 35,                      // 1 byte(s), unsigned
  SongNumber = 36,                  // 1 byte(s), unsigned
  SongPlaying = 37,                 // 1 byte(s), unsigned
  NumberOfStreamPackets = 38,       // 1 byte(s), unsigned
  RequestedVelocity = 39,           // 2 byte(s), signed, mm/s
  RequestedRadius = 40,             // 2 byte(s), signed, mm
  RequestedRightVelocity = 41,      // 2 byte(s), signed, mm/s
  RequestedLeftVelocity = 42,       // 2 byte(s), signed, mm/s
  LeftEncoderCounts = 43,           // 2 byte(s), signed, x*(pi*72.0/508.8) = distance in mm
  RightEncoderCounts = 44,          // 2 byte(s), signed, x*(pi*72.0/508.8) = distance in mm
  LightBumper = 45,                 // 1 byte(s), unsigned
  LightBumpLeftSignal = 46,         // 2 byte(s), unsigned
  LightBumpFrontLeftSignal = 47,    // 2 byte(s), unsigned
  LightBumpCenterLeftSignal = 48,   // 2 byte(s), unsigned
  LightBumpCenterRightSignal = 49,  // 2 byte(s), unsigned
  LightBumpFrontRightSignal = 50,   // 2 byte(s), unsigned
  LightBumpRightSignal = 51,        // 2 byte(s), unsigned
  LeftMotorCurrent = 54,            // 2 byte(s), signed, mA
  RightMotorCurrent = 55,           // 2 byte(s), signed, mA
  MainBrushCurrent = 56,            // 2 byte(s), signed, mA
  SideBrushCurrent = 57,            // 2 byte(s), signed, mA
  Stasis = 58,                      // 2 byte(s), signed, mA
};

enum class ChargeState : uint8_t {
  NotCharging = 0,
  ReconditioningCharging = 1,
  FullCharging = 2,
  TrickleCharging = 3,
  Waiting = 4,
  Fault = 5,
};

enum class OIMode : uint8_t {
  Off = 0,
  Passive = 1,
  Safe = 2,
  Full = 3,
};

enum class Activity : uint8_t {
  Docked,
  Charging,
  Cleaning,
  Lost,
};

}  // namespace roomba
}  // namespace esphome
