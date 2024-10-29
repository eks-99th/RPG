#pragma once
#include <vector>

#include "buff.hpp"
#include "types.hpp"

class statblock {
 private:
  stattype baseStrength;
  stattype baseInteligence;
  stattype baseAgility;
  stattype baseArmor;
  stattype baseElementRes;

  stattype totalStrengthFromBuffs = 0;
  stattype totalInteligenceFromBuffs = 0;
  stattype totalAgilityFromBuffs = 0;
  stattype totalArmorFromBuffs = 0;
  stattype totalElementResFromBuffs = 0;

 public:
  explicit statblock(stattype s, stattype i, stattype a,
                     stattype armor = static_cast<stattype>(0u),
                     stattype elres = static_cast<stattype>(0u))
      : baseStrength(s),
        baseInteligence(i),
        baseAgility(a),
        baseArmor(armor),
        baseElementRes(elres) {}

  auto getBaseStrength() const -> stattype { return baseStrength; }
  auto getBaseInteligence() const -> stattype { return baseInteligence; }
  auto getBaseAgility() const -> stattype { return baseAgility; }
  auto getBaseArmor() const -> stattype { return baseArmor; }
  auto getBaseElementRes() const -> stattype { return baseElementRes; }

  auto getTotalStrength() const -> stattype {
    return baseStrength + totalStrengthFromBuffs;
  }
  auto getTotalInteligence() const -> stattype {
    return baseInteligence + totalInteligenceFromBuffs;
  }
  auto getTotalAgility() const -> stattype {
    return baseAgility + totalAgilityFromBuffs;
  }
  auto getTotalArmor() const -> stattype {
    return baseArmor + totalArmorFromBuffs;
  }
  auto getTotalElementRes() const -> stattype {
    return baseElementRes + totalElementResFromBuffs;
  }

  statblock() {
    baseStrength = baseInteligence = baseAgility = static_cast<stattype>(1u);
  }

 protected:
  std::vector<buff> Buffs;

  void AddNewBuff(buff b) {
    for (auto& buff : Buffs) {
      if (buff.name == b.name) {
        buff.duration = b.duration;
        return;
      }
    }
    Buffs.push_back(b);
    recalculate_buffs();
  };

  void increaseStats(stattype s, stattype i, stattype a) {
    baseStrength += s;
    baseInteligence += i;
    baseAgility += a;
  }

 private:
  void recalculate_buffs() {
    stattype _strengthfrombuffs = 0;
    stattype _inteligencefrombuffs = 0;
    stattype _agilityfrombuffs = 0;
    stattype _armorfrombuffs = 0;
    stattype _elementresfrombuffs = 0;
    for (const auto& buff : Buffs) {
      if (buff.isDebuff) {
        _strengthfrombuffs -= buff.Strength;
        _inteligencefrombuffs -= buff.Inteligence;
        _agilityfrombuffs -= buff.Agility;
        _armorfrombuffs -= buff.Armor;
        _elementresfrombuffs -= buff.ElementRes;
      } else {
        _strengthfrombuffs += buff.Strength;
        _inteligencefrombuffs += buff.Inteligence;
        _agilityfrombuffs += buff.Agility;
        _armorfrombuffs += buff.Armor;
        _elementresfrombuffs += buff.ElementRes;
      }
      totalStrengthFromBuffs =
          (totalStrengthFromBuffs < 0) ? 0 : _strengthfrombuffs;
      totalInteligenceFromBuffs =
          (totalInteligenceFromBuffs < 0) ? 0 : _inteligencefrombuffs;
      totalAgilityFromBuffs =
          (totalAgilityFromBuffs < 0) ? 0 : _agilityfrombuffs;
      totalArmorFromBuffs = (totalArmorFromBuffs < 0) ? 0 : _armorfrombuffs;
      totalElementResFromBuffs =
          (totalElementResFromBuffs < 0) ? 0 : _elementresfrombuffs;
    }
  };
};
