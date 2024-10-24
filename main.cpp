#include <iostream>

#include "playercharacter.hpp"

auto main() -> int {
  auto c1 = new Wizzard();
  PlayerCharacter p1(c1);

  for (int i = 0; i < 2; i++) {
    std::cout << p1.getClassName() << " Level " << p1.getLevel() << '\n'
              << "-EXP: " << p1.getCurrentEXP() << '/' << p1.getEXPToNextLevel()
              << '\n'
              << "-HP: " << p1.getCurrentHP() << '/' << p1.getMaxHP() << '\n'
              << "-Stength: " << p1.getStrength() << '\n'
              << "-Intellect: " << p1.getIntelligence() << '\n';
    if (i < 1) p1.gainEXP(100u);
  }

  return 0;
}
