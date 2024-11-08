#include <iostream>

#include "playercharacter.hpp"

auto main() -> int {
  auto c1 = new Rogue();
  PlayerCharacter p1(c1);
  CoreStats leather_armor_stats(0, 0, 0, 5, 3);

  if (auto chest_armor = std::make_unique<armor>(
          "Leather Armor", leather_armor_stats, ARMORSLOTS::CHEST);
      p1.equip(std::move(chest_armor))) {
    std::cout << "Equipped\n";
  } else {
    std::cout << "Not Equipped\n";
  }

  CoreStats leather_helm_stats(0, 0, 0, 1, 1);
  if (auto LeatherHelm = std::make_unique<armor>(
          "Plain Leather Helmet", leather_helm_stats, ARMORSLOTS::HEAD);
      p1.equip(std::move(LeatherHelm))) {
    std::cout << "Equipped\n";
  } else {
    std::cout << "Not Equipped\n";
  }

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
    std::cout << "Abilities:\n";
    for (const auto& ability : p1.getAbilities()) {
      std::cout << "  -" << ability.name << '\n';
    }
    std::cout << "Equippment:\n";
    std::cout << "  -Chest: " << p1.getArmors(ARMORSLOTS::CHEST) << '\n';
    std::cout << "  -Head: " << p1.getArmors(ARMORSLOTS::HEAD) << '\n';
    std::cout << "  -Legs: " << p1.getArmors(ARMORSLOTS::LEGS) << '\n';
    if (i < 1) {
      p1.gainEXP(100u);
      p1.applyBuff(buff("Strength Buff", true, 2u, 50, 0, 0, 0, 0));
    }
  }

  return 0;
}
