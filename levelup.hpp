#pragma once
#include <cstdint>

using exptype = std::uint64_t;
using leveltype = std::uint16_t;

class LevelSystem {
 public:
  LevelSystem() {
    CurrentLevel = static_cast<leveltype>(1u);
    CurrentEXP = static_cast<leveltype>(0u);
    EXPToNextLevel = LEVEL2AT;
  }

  void gainExp(exptype exp) {
    CurrentEXP += exp;
    while (check_if_leveled()) {
    };
  }
  virtual void LevelUp() = 0;

  auto getLevel() -> leveltype { return CurrentLevel; }
  auto getCurrentEXP() -> exptype { return CurrentEXP; }
  auto getEXPToNextLevel() -> exptype { return EXPToNextLevel; }

 private:
  static const exptype LEVEL2AT = 100u;

 protected:
  leveltype CurrentLevel = 1u;
  leveltype CurrentEXP = 1u;
  exptype EXPToNextLevel;
  leveltype LevelUpsAvailable = 0u;

  auto check_if_leveled() -> bool {
    static const leveltype LEVELSCALAR = 2u;
    if (CurrentEXP >= EXPToNextLevel) {
      CurrentLevel++;
      LevelUp();
      EXPToNextLevel *= LEVELSCALAR;
      return true;
    }
    return false;
  }
};