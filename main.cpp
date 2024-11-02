#include <iostream>

#include "playercharacter.hpp"

auto main() -> int {
  auto c1 = new Rogue();
  PlayerCharacter p1(c1);

  for (int i = 0; i < 2; i++) {
    std::cout << p1.getClassName() << " Level " << p1.getLevel() << '\n'
              << "-EXP: " << p1.getCurrentEXP() << '/' << p1.getEXPToNextLevel()
              << '\n'
              << "-HP: " << p1.getCurrentHP() << '/' << p1.getMaxHP() << '\n'
              << "-MP: " << p1.getCurrentMP() << '/' << p1.getMaxMP() << '\n'
              << "-Stength: " << p1.getTotalStrength() << '\n'
              << "-Intellect: " << p1.getTotalIntelligence() << '\n'
              << "-Agility: " << p1.getTotalAgility() << '\n'
              << "-Armor: " << p1.getTotalArmor() << '\n'
              << "-Resistance: " << p1.getTotalElementRes() << '\n';
    for (const auto& ability : p1.getAbilities()) {
      std::cout << "  -" << ability.name << '\n';
    }
    if (i < 1) {
      p1.gainEXP(100u);
      p1.applyBuff(buff("Strength Buff", true, 2u, 50, 0, 0, 0, 0));
    }
  }

  return 0;
}
