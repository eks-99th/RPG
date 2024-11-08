#pragma once
#include <string>
#include <typeinfo>

#include "corestats.hpp"

class equipment {
 public:
  std::string name;
  CoreStats stats;
  virtual auto GetType() const -> const std::string = 0;

 protected:
  equipment(std::string name, CoreStats stats)
      : name(std::move(name)), stats(stats) {}
};

enum class ARMORSLOTS {
  HEAD,
  CHEST,
  LEGS,
  FEET,
  HANDS,
  RING1,
  RING2,
  NECKLACE,
  NUM_SLOTS
};

class armor final : public equipment {
 public:
  ARMORSLOTS slot;
  armor() = delete;
  armor(const armor&) = delete;
  armor(armor&&) = delete;
  armor(const std::string& name, CoreStats stats, ARMORSLOTS slot)
      : equipment(name, stats), slot(slot) {}

  auto GetType() const -> const std::string override {
    return typeid(*this).name();
  }
};

enum class WEAPONSLOT { MELEE1, RANGED, NUM_SLOTS };

class weapon final : public equipment {
 public:
  WEAPONSLOT slot;
  damagetype MinDamage;
  damagetype MaxDamage;
  bool twoHanded;
  weapon() = delete;
  weapon(const weapon&) = delete;
  weapon(weapon&&) = delete;
  weapon(const std::string& name, CoreStats stats, WEAPONSLOT slot,
         damagetype _MinDamage, damagetype _MaxDamage, bool _twoHanded = false)
      : equipment(name, stats),
        slot(slot),
        MinDamage(_MinDamage),
        MaxDamage(_MaxDamage),
        twoHanded(_twoHanded) {}

  auto GetType() const -> const std::string override {
    return typeid(*this).name();
  }
};