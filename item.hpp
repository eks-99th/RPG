#pragma once
#include <string>
#include <typeinfo>

#include "corestats.hpp"
#include "item_manager.hpp"

#define GETTYPE                                      \
  auto GetType() const->const std::string override { \
    return typeid(*this).name();                     \
  }

class itemDelegate {
 public:
  std::string name;
  virtual auto GetType() const -> const std::string = 0;
  virtual ~itemDelegate() = default;

 protected:
  itemDelegate(std::string _name) : name(std::move(_name)){};
};

class item {
 public:
 private:
  std::unique_ptr<itemDelegate> data;
  item(std::unique_ptr<itemDelegate> delegate) : data(std::move(delegate)) {}
  friend class ItemManager;
  friend class PlayerCharacter;
};

class equipmentDelegate : public itemDelegate {
 public:
  CoreStats stats;
  const std::uint32_t Unique_Id = Unique_Id_Counter++;

 protected:
  static std::uint32_t Unique_Id_Counter;
  equipmentDelegate(std::string _name, CoreStats _stats)
      : itemDelegate(std::move(_name)), stats(_stats){};
};

std::uint32_t equipmentDelegate::Unique_Id_Counter = 0;

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

class armor final : public equipmentDelegate {
 public:
  ARMORSLOTS slot;
  armor() = delete;
  armor(const armor&) = delete;
  armor(armor&&) = delete;

 protected:
  armor(const std::string& name, CoreStats stats, ARMORSLOTS slot)
      : equipmentDelegate(name, stats), slot(slot) {}

  GETTYPE

  friend class ItemManager;
};

class Potion final : public itemDelegate {
 public:
  welltype healamount;
  std::unique_ptr<buff> pbuff;
  itemcount Quantity;
  GETTYPE

 private:
  Potion(std::string _name, std::unique_ptr<buff> _buff, welltype _amount,
         itemcount _count = 1)
      : itemDelegate(_name),
        healamount(_amount),
        pbuff(std::move(_buff)),
        Quantity(_count) {}
  friend class ItemManager;
};

enum class WEAPONSLOT { MELEE1, RANGED, NUM_SLOTS };

class weapon final : public equipmentDelegate {
 public:
  WEAPONSLOT slot;
  damagetype MinDamage;
  damagetype MaxDamage;
  bool twoHanded;
  weapon() = delete;
  weapon(const weapon&) = delete;
  weapon(weapon&&) = delete;

 private:
  weapon(const std::string& name, CoreStats stats, WEAPONSLOT slot,
         damagetype _MinDamage, damagetype _MaxDamage, bool _twoHanded = false)
      : equipmentDelegate(name, stats),
        slot(slot),
        MinDamage(_MinDamage),
        MaxDamage(_MaxDamage),
        twoHanded(_twoHanded) {}

  GETTYPE
  friend class ItemManager;
};
