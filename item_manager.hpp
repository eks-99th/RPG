#pragma once
#include <memory>

#include "item.hpp"

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
};