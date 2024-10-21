#pragma once

#include "hp.hpp"
#include "statblock.hpp"

class Cleric : public hp, public statblock {
 public:
  static const hptype HPGROWTH = static_cast<hptype>(14u);
  static const stattype BASESTR = static_cast<stattype>(2u);
  static const stattype BASEINT = static_cast<stattype>(3u);
  Cleric() : hp(HPGROWTH, HPGROWTH), statblock(BASESTR, BASEINT) {}

 private:
};