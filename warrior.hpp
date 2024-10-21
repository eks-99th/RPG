#pragma once

#include "hp.hpp"
#include "statblock.hpp"

class Warrior : public hp, public statblock {
 public:
  static const hptype HPGROWTH = static_cast<hptype>(19u);
  static const stattype BASESTR = static_cast<stattype>(4u);
  static const stattype BASEINT = static_cast<stattype>(1u);
  Warrior() : hp(HPGROWTH, HPGROWTH), statblock(BASESTR, BASEINT) {}

 private:
};