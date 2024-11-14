#pragma once
#include <memory>

#include "buff.hpp"
#include "item.hpp"
#include "pointwell.hpp"

class ItemManager {
 public:
  static std::unique_ptr<item> CreateArmor(const std::string& name,
                                           CoreStats stats, ARMORSLOTS slot) {
    auto armor_delegate = std::unique_ptr<armor>(new armor(name, stats, slot));
    return std::unique_ptr<item>(new item(std::move(armor_delegate)));
  }

  static std::unique_ptr<item> CreateWeapon(const std::string& name,
                                            CoreStats stats, WEAPONSLOT slot,
                                            damagetype _MinDamage,
                                            damagetype _MaxDamage,
                                            bool _twoHanded = false) {
    auto weapon_delegate = std::unique_ptr<weapon>(
        new weapon(name, stats, slot, _MinDamage, _MaxDamage, _twoHanded));
    return std::unique_ptr<item>(new item(std::move(weapon_delegate)));
  }

  static std::unique_ptr<item> CreatePotion(const std::string& name,
                                            std::unique_ptr<buff> buff,
                                            welltype heal_amount,
                                            itemcount _count = 1) {
    auto potion_delegate = std::unique_ptr<Potion>(
        new Potion(name, std::move(buff), heal_amount, _count));
    // (std::string _name, buff* b, welltype _amount, itemcount _count = 1)
    return std::unique_ptr<item>(new item(std::move(potion_delegate)));
    return 0;
  }
};