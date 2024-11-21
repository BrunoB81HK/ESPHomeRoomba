#pragma once

#include <cstdint>
#include <type_traits>

namespace esphome {
namespace roomba {

template<typename Enum, typename std::enable_if<std::is_enum<Enum>::value, bool>::type = true>
constexpr Enum operator|(const Enum lhs, const Enum rhs) noexcept {
  using underlying = typename std::underlying_type<Enum>::type;
  return static_cast<Enum>(static_cast<underlying>(lhs) | static_cast<underlying>(rhs));
}

enum class LEDMask : uint8_t {
  Debris = 0x01 << 0,
  Spot = 0x01 << 1,
  Dock = 0x01 << 2,
  CheckRobot = 0x01 << 3,
};

enum class WeekdayLEDMask : uint8_t {
  Sunday = 0x01 << 0,
  Monday = 0x01 << 1,
  Tuesday = 0x01 << 2,
  Wednesday = 0x01 << 3,
  Thursday = 0x01 << 4,
  Friday = 0x01 << 5,
  Saturday = 0x01 << 6,
};

enum class SchedulingLEDMask : uint8_t {
  Colon = 0x01 << 0,
  PM = 0x01 << 1,
  AM = 0x01 << 2,
  Clock = 0x01 << 3,
  Schedule = 0x01 << 4,
};

enum class DigitLEDMask : uint8_t {
  A = 0x01 << 0,  // Top
  B = 0x01 << 1,  // Top Right
  C = 0x01 << 2,  // Bottom Right
  D = 0x01 << 3,  // Bottom
  E = 0x01 << 4,  // Bottom Left
  F = 0x01 << 5,  // Top Left
  G = 0x01 << 6,  // Middle
};

enum class BumpsAndWheelDropsMask : uint8_t {
  BumpsRight = 0x01 << 0,
  BumpsLeft = 0x01 << 1,
  WheelDropRight = 0x01 << 2,
  WheelDropLeft = 0x01 << 3,
};

enum class WheelOvercurrentsMask : uint8_t {
  SideBrush = 0x01 << 0,
  MainBrush = 0x01 << 2,
  RightWheel = 0x01 << 3,
  LeftWheel = 0x01 << 4,
};

enum class ButtonMask : uint8_t {
  Clean = 0x01 << 0,
  Spot = 0x01 << 1,
  Dock = 0x01 << 2,
  Minute = 0x01 << 3,
  Hour = 0x01 << 4,
  Day = 0x01 << 5,
  Schedule = 0x01 << 6,
  Clock = 0x01 << 7,
};

enum class ChargingSourceMask : uint8_t {
  InternalCharger = 0x01 << 0,
  HomeBase = 0x01 << 1,
};

enum class LightBumperMask : uint8_t {
  Left = 0x01 << 0,
  FrontLeft = 0x01 << 1,
  CenterLeft = 0x01 << 2,
  CenterRight = 0x01 << 3,
  FrontRight = 0x01 << 4,
  Right = 0x01 << 5,
};

enum class StasisMask : uint8_t {
  Toggling = 0x01 << 0,
  Disabled = 0x01 << 1,
};

}  // namespace roomba
}  // namespace esphome
