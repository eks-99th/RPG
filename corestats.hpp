#pragma once
#include <limits>

#include "types.hpp"

struct CoreStats {
 public:
  explicit CoreStats(stattype s = 0, stattype i = 0, stattype a = 0,
                     stattype arm = 0, stattype elres = 0)
      : Strength(s),
        Inteligence(i),
        Agility(a),
        Armor(arm),
        ElementRes(elres){};

  stattype Strength;
  stattype Inteligence;
  stattype Agility;
  stattype Armor;
  stattype ElementRes;

  auto operator+=(const CoreStats& rhs) -> CoreStats& {
    this->Strength = addWithOverflowcheck(this->Strength, rhs.Strength);
    this->Inteligence =
        addWithOverflowcheck(this->Inteligence, rhs.Inteligence);
    this->Agility = addWithOverflowcheck(this->Agility, rhs.Agility);
    this->Armor = addWithOverflowcheck(this->Armor, rhs.Armor);
    this->ElementRes = addWithOverflowcheck(this->ElementRes, rhs.ElementRes);
    return *this;
  };

  auto addWithOverflowcheck(stattype const base, stattype const add_val) const
      -> stattype {
    return (base + add_val < base) ? std::numeric_limits<stattype>::max()
                                   : base + add_val;
  }

  auto operator+(const CoreStats& rhs) const -> CoreStats {
    CoreStats temp = *this;
    temp += rhs;
    return temp;
  };

  auto operator-=(const CoreStats& rhs) -> CoreStats& {
    this->Strength = subtractWithUnderflowcheck(this->Strength, rhs.Strength);
    this->Inteligence =
        subtractWithUnderflowcheck(this->Inteligence, rhs.Inteligence);
    this->Agility = subtractWithUnderflowcheck(this->Agility, rhs.Agility);
    this->Armor = subtractWithUnderflowcheck(this->Armor, rhs.Armor);
    this->ElementRes =
        subtractWithUnderflowcheck(this->ElementRes, rhs.ElementRes);
    return *this;
  }

  auto subtractWithUnderflowcheck(stattype const base,
                                  stattype const sub_val) const -> stattype {
    return (base < sub_val) ? 0 : base - sub_val;
  }
};