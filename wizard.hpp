#pragma once

#include "hp.hpp"
#include "levelup.hpp"
#include "statblock.hpp"

class Wizard : public hp, public statblock, public LevelSystem {
 public:
  static const hptype BASEHP = static_cast<hptype>(9u);
  static const stattype BASESTR = static_cast<stattype>(1u);
  static const stattype BASEINT = static_cast<stattype>(4u);
  Wizard() : hp(BASEHP, BASEHP), statblock(BASESTR, BASEINT) {}

 private:
  static const hptype HPGROWTH = static_cast<hptype>(6u);
  static const stattype STRGROWTH = static_cast<stattype>(2u);
  static const stattype INTGROWTH = static_cast<stattype>(1u);
  void LevelUp() override {
    setMaxHP(HPGROWTH + getMaxHp());
    increaseStats(STRGROWTH, INTGROWTH);
  }
};