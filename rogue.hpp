#pragma once

#include "hp.hpp"
#include "statblock.hpp"

class Rogue : public hp, public statblock {
 public:
  static const hptype HPGROWTH = static_cast<hptype>(13u);
  static const stattype BASESTR = static_cast<stattype>(3u);
  static const stattype BASEINT = static_cast<stattype>(1u);
  Rogue() : hp(HPGROWTH, HPGROWTH), statblock(BASESTR, BASEINT) {}

 private:
};