#pragma once

#include "hp.hpp"
#include "levelup.hpp"
#include "statblock.hpp"

class Cleric : public hp, public statblock, public LevelSystem {
 public:
  static const hptype BASEHP = static_cast<hptype>(14u);
  static const stattype BASESTR = static_cast<stattype>(2u);
  static const stattype BASEINT = static_cast<stattype>(3u);

  static const hptype HPGROWTH = static_cast<hptype>(7u);
  static const stattype STRGROWTH = static_cast<stattype>(1u);
  static const stattype INTGROWTH = static_cast<stattype>(2u);

  Cleric() : hp(BASEHP, BASEHP), statblock(BASESTR, BASEINT) {}

 private:
  void LevelUp() override {
    setMaxHP(HPGROWTH + getMaxHp());
    increaseStats(STRGROWTH, INTGROWTH);
  }
};