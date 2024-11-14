#include <iostream>

#include "item_manager.hpp"
#include "playercharacter.hpp"

auto main() -> int {
  PlayerCharacter p1(new Warrior());
  CoreStats leather_armor_stats(0, 0, 0, 5, 3);
  auto chest_armor = ItemManager::CreateArmor(
      "Leather Armor", leather_armor_stats, ARMORSLOTS::CHEST);
  if (p1.equip(std::move(chest_armor))) {
    std::cout << "Equipped Leather Armor\n";
  } else {
    std::cout << "Not Equipped\n";
  }
  auto leather_helm_stats = CoreStats(0, 0, 0, 1, 1);
  auto LeatherHelm = ItemManager::CreateArmor(
      "Plain Leather Helmet", leather_helm_stats, ARMORSLOTS::HEAD);
  if (p1.equip(std::move(LeatherHelm))) {
    std::cout << "Equipped Plain Leather Helmet\n";
  } else {
    std::cout << "Not Equipped\n";
  }
  auto LongSword = ItemManager::CreateWeapon(
      "Long Sword", CoreStats(0, 0, 0, 0, 0), WEAPONSLOT::MELEE1, 5, 10);
  if (p1.equip(std::move(LongSword))) {
    std::cout << "Equipped Long Sword\n";
  } else {
    std::cout << "Not Equipped\n";
  }
  auto MinorHealingPotionBuff =
      std::make_unique<buff>("Minor Healing Potion", false, 0, 0, 0, 0, 0, 10);
  auto MinorPotion = ItemManager::CreatePotion(
      "Minor Healing Potion", std::move(MinorHealingPotionBuff), 10);

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
  std::cout << "Player took 10 damage\n";
  p1.takeDamage(10);
  std::cout << "Player health is now " << p1.getCurrentHP() << "/"
            << p1.getMaxHP() << '\n';
  std::cout << "Player used a potion\n";
  p1.use_item(std::move(MinorPotion));
  std::cout << "Player health is now " << p1.getCurrentHP() << "/"
            << p1.getMaxHP() << '\n';
  return 0;
}
