#include "hitpointtypes.hpp"

class hp {
 private:
  hptype CurrentHP;
  hptype MaxHP;

 public:
  bool setMaxHP(hptype new_max_hp);
  hptype getMaxHp();
  hptype getCurrentHP();
  void takeDamage(hptype damage);
  void heal(hptype amount);
  hp(/* args */);
  ~hp();
};

hp::hp(/* args */) {}

hp::~hp() {}

bool hp::setMaxHP(hptype new_max_hp) {
  if (new_max_hp < 1) {
    return false;
  }
  MaxHP = new_max_hp;
  if (CurrentHP > MaxHP) {
    CurrentHP = MaxHP;
  }
  return true;
}

hptype hp::getMaxHp() { return MaxHP; }

hptype hp::getCurrentHP() { return CurrentHP; }

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