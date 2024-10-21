#pragma once
#include "hitpointtypes.hpp"

class hp {
 private:
  hptype CurrentHP;
  hptype MaxHP;

 public:
  auto setMaxHP(hptype new_max_hp) -> bool;
  auto getMaxHp() -> hptype;
  auto getCurrentHP() -> hptype;
  void takeDamage(hptype damage);
  void heal(hptype amount);
  hp();
  hp(hptype cHP, hptype mHP) {
    CurrentHP = cHP;
    MaxHP = mHP;
    if (CurrentHP > MaxHP) CurrentHP = MaxHP;
  }
};

hp::hp() {
  CurrentHP = 1;
  MaxHP = 1;
}

auto hp::setMaxHP(hptype new_max_hp) -> bool {
  if (new_max_hp < 1) {
    return false;
  }
  MaxHP = new_max_hp;
  if (CurrentHP > MaxHP) {
    CurrentHP = MaxHP;
  }
  return true;
}

auto hp::getMaxHp() -> hptype { return MaxHP; }

auto hp::getCurrentHP() -> hptype { return CurrentHP; }

void hp::takeDamage(hptype damage) {
  if (damage > CurrentHP) {
    CurrentHP = 0;
  } else {
    CurrentHP -= damage;
  }
}

void hp::heal(hptype amount) {
  if (CurrentHP + amount > MaxHP) {
    CurrentHP = MaxHP;
  } else {
    CurrentHP += amount;
  }
}