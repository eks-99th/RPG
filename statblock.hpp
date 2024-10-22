#pragma once
#include "stattypes.hpp"

class statblock {
 private:
  stattype Strength;
  stattype Inteligence;

 public:
  explicit statblock(stattype s, stattype i) {
    Strength = s;
    Inteligence = i;
  }

  auto getStrength() -> stattype { return Strength; }
  auto getInteligence() -> stattype { return Inteligence; }

  statblock() {
    Strength = 1;
    Inteligence = 1;
  }

 protected:
  void increaseStats(stattype s, stattype i) {
    Strength += s;
    Inteligence += i;
  }
};
