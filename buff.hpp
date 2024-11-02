#pragma once
#include <cstdint>
#include <string>

#include "corestats.hpp"
#include "types.hpp"

struct buff {
  explicit buff(std::string name, bool isDebuff = false, std::uint16_t dur = 2u,
                stattype str = 0, stattype intel = 0, stattype agi = 0,
                stattype arm = 0, stattype elres = 0)
      : name(std::move(name)),
        isDebuff(isDebuff),
        duration(dur),
        buffedStats(CoreStats(str, intel, agi, arm, elres)) {}

  explicit buff(std::string name, bool isDebuff = false, std::uint16_t dur = 2u,
                CoreStats stats = CoreStats(0, 0, 0, 0, 0))
      : name(std::move(name)),
        isDebuff(isDebuff),
        duration(dur),
        buffedStats(stats) {}

  std::string name;
  bool isDebuff;
  std::uint16_t duration;
  CoreStats buffedStats;
};
