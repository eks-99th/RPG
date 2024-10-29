#pragma once
#include <cstdint>
#include <string>

#include "types.hpp"
struct buff {
  buff(std::string name, bool isDebuff, std::uint16_t dur, stattype str,
       stattype intel, stattype agi, stattype arm, stattype elres)
      : name(std::move(name)),
        isDebuff(isDebuff),
        duration(dur),
        Strength(str),
        Inteligence(intel),
        Agility(agi),
        Armor(arm),
        ElementRes(elres) {}
  std::string name;
  bool isDebuff;
  std::uint16_t duration;
  stattype Strength;
  stattype Inteligence;
  stattype Agility;
  stattype Armor;
  stattype ElementRes;
};
