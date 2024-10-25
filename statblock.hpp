#pragma once
#include "stattypes.hpp"

class statblock {
 private:
  stattype Strength;
  stattype Inteligence;
  stattype Agility;
  stattype Armor;
  stattype ElementRes;

 public:
  explicit statblock(stattype s, stattype i, stattype a,
                     stattype armor = static_cast<stattype>(0u),
                     stattype elres = static_cast<stattype>(0u))
      : Strength(s),
        Inteligence(i),
        Agility(a),
        Armor(armor),
        ElementRes(elres) {}

  auto getStrength() const -> stattype { return Strength; }
  auto getInteligence() const -> stattype { return Inteligence; }
  auto getAgility() const -> stattype { return Agility; }
  auto getArmor() const -> stattype { return Armor; }
  auto getElementRes() const -> stattype { return ElementRes; }

  statblock() { Strength = Inteligence = Agility = static_cast<stattype>(1u); }

 protected:
  void increaseStats(stattype s, stattype i, stattype a) {
    Strength += s;
    Inteligence += i;
    Agility += a;
  }
};
