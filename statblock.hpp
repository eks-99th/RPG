#pragma once
#include <limits>
#include <vector>

#include "buff.hpp"
#include "corestats.hpp"

class statblock {
 private:
  CoreStats base;
  CoreStats fromBuffs;

 public:
  explicit statblock(stattype s, stattype i, stattype a,
                     stattype armor = static_cast<stattype>(0u),
                     stattype elres = static_cast<stattype>(0u)) {
    base.Strength = s;
    base.Inteligence = i;
    base.Agility = a;
    base.Armor = armor;
    base.ElementRes = elres;
  }

  auto getBaseStrength() const -> stattype { return base.Strength; }
  auto getBaseInteligence() const -> stattype { return base.Inteligence; }
  auto getBaseAgility() const -> stattype { return base.Agility; }
  auto getBaseArmor() const -> stattype { return base.Armor; }
  auto getBaseElementRes() const -> stattype { return base.ElementRes; }

  auto getTotalStrength() const -> stattype {
    return base.Strength + fromBuffs.Strength;
  }
  auto getTotalInteligence() const -> stattype {
    return base.Inteligence + fromBuffs.Inteligence;
  }
  auto getTotalAgility() const -> stattype {
    return base.Agility + fromBuffs.Agility;
  }
  auto getTotalArmor() const -> stattype {
    return base.Armor + fromBuffs.Armor;
  }
  auto getTotalElementRes() const -> stattype {
    return base.ElementRes + fromBuffs.ElementRes;
  }

  statblock() {
    base.Strength = base.Inteligence = base.Agility = static_cast<stattype>(1u);
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

  void increaseStats(stattype s = 0, stattype i = 0, stattype a = 0,
                     stattype arm = 0, stattype elres = 0) {
    base.Strength += s;
    base.Inteligence += i;
    base.Agility += a;
    base.Armor += arm;
    base.ElementRes += elres;
  }

  void increaseStats(CoreStats cs) { base += cs; }

 private:
  void recalculate_buffs() {
    auto tempTotalStats = CoreStats(0, 0, 0, 0, 0);

    for (const auto& buff : Buffs) {
      if (buff.isDebuff) {
        tempTotalStats -= buff.buffedStats;
      } else {
        tempTotalStats += buff.buffedStats;
      }
      fromBuffs = tempTotalStats;
    }
  };
};
