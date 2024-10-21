#pragma once

#include "hp.hpp"
#include "statblock.hpp"

class Wizard : public hp, public statblock {
 public:
  static const hptype HPGROWTH = static_cast<hptype>(9u);
  static const stattype BASESTR = static_cast<stattype>(1u);
  static const stattype BASEINT = static_cast<stattype>(4u);
  Wizard() : hp(HPGROWTH, HPGROWTH), statblock(BASESTR, BASEINT) {}

 private:
};