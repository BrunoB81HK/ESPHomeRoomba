#pragma once

#include <cstdint>

namespace esphome {
namespace roomba {

template<typename T>
constexpr std::enable_if_t<
    std::conjunction_v<std::is_enum<T>, std::is_same<bool, decltype(enable_bitmask_operator_or(std::declval<T>()))>>, T>
operator|(const T lhs, const T rhs) {
  using underlying = std::underlying_type_t<T>;

  return static_cast<T>(static_cast<underlying>(lhs) | static_cast<underlying>(rhs));
}

enum class BumpsAndWheelDropsMasks : uint8_t {
  bumps_right = 0x01 << 0,
  bumps_left = 0x01 << 1,
  wheel_drop_right = 0x01 << 2,
  wheel_drop_left = 0x01 << 3,
};

}  // namespace roomba
}  // namespace esphome
