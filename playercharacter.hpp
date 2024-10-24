#pragma once
#include <cstdint>
#include <memory>
#include <string>

#include "pointwell.hpp"
#include "statblock.hpp"

using exptype = std::uint64_t;
using leveltype = std::uint16_t;

#define PCCONSTRUCT            \
  HP->setMax(BASEHP);          \
  HP->increaseCurrent(BASEHP); \
  increaseStats(BASESTR, BASEINT);

#define LEVELUP                                                        \
  auto new_max = static_cast<welltype>((BASEHP / 2.f) + HP->getMax()); \
  auto new_current = static_cast<welltype>((BASEHP / 2.f));            \
  HP->setMax(new_max);                                                 \
  HP->increaseCurrent(new_current);                                    \
  auto new_str = static_cast<stattype>((BASESTR + 1u) / 2.f);          \
  auto new_int = static_cast<stattype>((BASEINT + 1u) / 2.f);          \
  increaseStats(new_str, new_int);

class PlayerCharacterDelegate : public statblock {
 public:
  PlayerCharacterDelegate()
      : statblock(0, 0),
        HP(std::make_unique<PointWell>()),
        CurrentLevel(static_cast<leveltype>(1u)),
        CurrentEXP(static_cast<leveltype>(0u)) {
    // Constructor body is now empty, as all members are initialized in the
    // initializer list
  }
  virtual ~PlayerCharacterDelegate() = default;
  void gainExp(exptype exp) {
    CurrentEXP += exp;
    while (check_if_leveled()) {
      // Do nothing
    };
  }
  virtual void LevelUp() = 0;
  virtual auto getClassName() -> std::string = 0;

  std::unique_ptr<PointWell> HP = nullptr;

  auto getLevel() const -> leveltype { return CurrentLevel; }
  auto getCurrentEXP() const -> exptype { return CurrentEXP; }
  auto getEXPToNextLevel() const -> exptype { return EXPToNextLevel; }

 private:
  static const exptype LEVEL2AT = 100u;
  leveltype CurrentLevel = 1u;
  leveltype CurrentEXP = 1u;
  exptype EXPToNextLevel = LEVEL2AT;

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

class PlayerCharacter {
 private:
  std::unique_ptr<PlayerCharacterDelegate> pcclass;

 public:
  PlayerCharacter() = delete;
  explicit PlayerCharacter(PlayerCharacterDelegate* pc) : pcclass(pc) {}
  auto getClassName() -> std::string { return pcclass->getClassName(); }
  auto getLevel() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getLevel());
  }
  auto getCurrentEXP() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getCurrentEXP());
  }
  auto getEXPToNextLevel() const -> exptype {
    return static_cast<uint16_t>(pcclass->getEXPToNextLevel());
  }
  auto getCurrentHP() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->HP->getCurrent());
  }
  auto getMaxHP() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->HP->getMax());
  }
  auto getStrength() -> uint16_t {
    return static_cast<uint16_t>(pcclass->getStrength());
  }
  auto getIntelligence() -> uint16_t {
    return static_cast<uint16_t>(pcclass->getInteligence());
  }
  auto gainEXP(exptype exp) -> void { pcclass->gainExp(exp); }
  auto takeDamage(welltype damage) -> void {
    pcclass->HP->reduceCurrent(damage);
  }
  auto healDamage(welltype amount) -> void {
    pcclass->HP->increaseCurrent(amount);
  }
};

class Cleric : public PlayerCharacterDelegate {
 public:
  static const welltype BASEHP = static_cast<welltype>(14u);
  static const stattype BASESTR = static_cast<stattype>(2u);
  static const stattype BASEINT = static_cast<stattype>(3u);
  Cleric() : PlayerCharacterDelegate() { PCCONSTRUCT }
  auto getClassName() -> std::string override { return "Cleric"; }

 private:
  void LevelUp() override { LEVELUP }
};

class Wizzard : public PlayerCharacterDelegate {
 public:
  static const welltype BASEHP = static_cast<welltype>(10u);
  static const stattype BASESTR = static_cast<stattype>(1u);
  static const stattype BASEINT = static_cast<stattype>(4u);

  Wizzard() : PlayerCharacterDelegate() { PCCONSTRUCT }
  auto getClassName() -> std::string override { return "Wizzard"; }

 private:
  void LevelUp() override { LEVELUP }
};

class Rogue : public PlayerCharacterDelegate {
 public:
  static const welltype BASEHP = static_cast<welltype>(12u);
  static const stattype BASESTR = static_cast<stattype>(3u);
  static const stattype BASEINT = static_cast<stattype>(1u);
  Rogue() : PlayerCharacterDelegate() { PCCONSTRUCT }
  auto getClassName() -> std::string override { return "Rogue"; }

 private:
  void LevelUp() override { LEVELUP }
};

class Warrior : public PlayerCharacterDelegate {
 public:
  static const welltype BASEHP = static_cast<welltype>(18u);
  static const stattype BASESTR = static_cast<stattype>(4u);
  static const stattype BASEINT = static_cast<stattype>(1u);
  Warrior() : PlayerCharacterDelegate() { PCCONSTRUCT }
  auto getClassName() -> std::string override { return "Warrior"; }

 private:
  void LevelUp() override { LEVELUP }
};