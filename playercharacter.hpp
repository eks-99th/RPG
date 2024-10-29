#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "ability.hpp"
#include "pointwell.hpp"
#include "statblock.hpp"
#include "types.hpp"

using exptype = std::uint64_t;
using leveltype = std::uint16_t;

class PlayerCharacterDelegate : public statblock {
 public:
  PlayerCharacterDelegate()
      : statblock(0, 0, 0),
        CurrentLevel(static_cast<leveltype>(1u)),
        CurrentEXP(static_cast<leveltype>(0u)) {
    HP = std::make_unique<PointWell>(1u, 1u);
  }
  virtual ~PlayerCharacterDelegate() = default;
  void gainExp(exptype exp) {
    CurrentEXP += exp;
    while (check_if_leveled()) {
      // Do nothing
    };
  }

  void applyBuff(buff b) {
    for (auto& buff : Buffs) {
      if (buff.name == b.name) {
        buff.duration = b.duration;
        return;
      }
    }
    AddNewBuff(b);
    // Strength += b.Strength;
    // Inteligence += b.Inteligence;
    // Agility += b.Agility;
    // Armor += b.Armor;
    // ElementRes += b.ElementRes;
  }

  virtual void LevelUp() = 0;
  virtual auto getClassName() -> std::string = 0;

  std::unique_ptr<PointWell> HP;
  std::unique_ptr<PointWell> MP;
  std::vector<Ability> Abilities;

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

  auto getCurrentMP() const -> uint16_t {
    if (!pcclass->MP) return 0;
    return static_cast<uint16_t>(pcclass->MP->getCurrent());
  }
  auto getMaxMP() const -> uint16_t {
    if (!pcclass->MP) return 0;
    return static_cast<uint16_t>(pcclass->MP->getMax());
  }

  auto getBaseStrength() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getBaseStrength());
  }

  auto getTotalStrength() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getTotalStrength());
  }

  auto getBaseIntelligence() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getBaseInteligence());
  }

  auto getTotalIntelligence() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getTotalInteligence());
  }

  auto getBaseAgility() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getBaseAgility());
  }

  auto getTotalAgility() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getTotalAgility());
  }

  auto getBaseArmor() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getBaseArmor());
  }

  auto getTotalArmor() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getTotalArmor());
  }

  auto getTotalElementRes() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getTotalElementRes());
  }

  auto getBaseElementRes() const -> uint16_t {
    return static_cast<uint16_t>(pcclass->getBaseElementRes());
  }

  auto getAbilities() -> std::vector<Ability> { return pcclass->Abilities; }

  auto gainEXP(exptype exp) -> void { pcclass->gainExp(exp); }
  auto takeDamage(welltype damage) -> void {
    pcclass->HP->reduceCurrent(damage);
  }
  auto healDamage(welltype amount) -> void {
    pcclass->HP->increaseCurrent(amount);
  }

  auto applyBuff(buff buff) -> void { pcclass->applyBuff(buff); }
};

#define PCCONSTRUCT              \
  HP->setMax(BASEHP);            \
  HP->increaseCurrent(BASEHP);   \
  if (MP) {                      \
    MP->setMax(BASEMP);          \
    MP->increaseCurrent(BASEMP); \
  }                              \
  increaseStats(BASESTR, BASEINT, BASEAGI);

#define LEVELUP                                                        \
  auto new_max = static_cast<welltype>((BASEHP / 2.f) + HP->getMax()); \
  auto new_current = static_cast<welltype>((BASEHP / 2.f));            \
  HP->setMax(new_max);                                                 \
  HP->increaseCurrent(new_current);                                    \
  if (MP) {                                                            \
    new_max = ((BASEMP / 2.f) + MP->getMax());                         \
    new_current = ((BASEMP / 2.f));                                    \
    MP->setMax(new_max);                                               \
    MP->increaseCurrent(new_current);                                  \
  }                                                                    \
  auto new_str = static_cast<stattype>((BASESTR + 1u) / 2.f);          \
  auto new_int = static_cast<stattype>((BASEINT + 1u) / 2.f);          \
  auto new_agi = static_cast<stattype>((BASEAGI + 1u) / 2.f);          \
  increaseStats(new_str, new_int, new_agi);

// #define CHARACTERCLASS(classname, basehp, basestr, baseint, baseagi)   \
//   class classname : public PlayerCharacterDelegate {                   \
//    public:                                                             \
//     static const welltype BASEHP = static_cast<welltype>(basehp);      \
//     static const stattype BASESTR = static_cast<stattype>(basestr);    \
//     static const stattype BASEINT = static_cast<stattype>(baseint);    \
//     static const stattype BASEAGI = static_cast<stattype>(baseagi);    \
//     classname() : PlayerCharacterDelegate() { PCCONSTRUCT }            \
//     auto getClassName() -> std::string override { return #classname; } \
//                                                                        \
//    private:                                                            \
//     void LevelUp() override { LEVELUP }                                \
//   };

class Cleric : public PlayerCharacterDelegate {
 public:
  static constexpr welltype BASEHP = static_cast<welltype>(14u);
  static constexpr welltype BASEMP = static_cast<welltype>(10u);
  static constexpr stattype BASESTR = static_cast<stattype>(3u);
  static constexpr stattype BASEINT = static_cast<stattype>(5u);
  static constexpr stattype BASEAGI = static_cast<stattype>(1u);

  Cleric() : PlayerCharacterDelegate() {
    MP = std::make_unique<PointWell>(BASEMP, BASEMP);
    PCCONSTRUCT
    Abilities.emplace_back("Heal", 2u, 1u, ABILITYTARGET::ALLY, 2u,
                           ABILITYSCALER::INT);
  }
  auto getClassName() -> std::string override { return "Cleric"; }

 private:
  void LevelUp() override {
    LEVELUP
    Abilities.emplace_back("Smite", 2u, 1u, ABILITYTARGET::ENEMY, 2u,
                           ABILITYSCALER::INT);
  }
};

class Wizzard : public PlayerCharacterDelegate {
 public:
  static constexpr welltype BASEHP = static_cast<welltype>(10u);
  static constexpr welltype BASEMP = static_cast<welltype>(14u);
  static constexpr stattype BASESTR = static_cast<stattype>(1u);
  static constexpr stattype BASEINT = static_cast<stattype>(8u);
  static constexpr stattype BASEAGI = static_cast<stattype>(1u);

  Wizzard() : PlayerCharacterDelegate() {
    MP = std::make_unique<PointWell>(BASEMP, BASEMP);
    PCCONSTRUCT
    Abilities.emplace_back("Firebolt", 2u, 1u, ABILITYTARGET::ENEMY, 4u,
                           ABILITYSCALER::INT);
  }
  auto getClassName() -> std::string override { return "Wizzard"; }

 private:
  void LevelUp() override {
    LEVELUP
    if (getLevel() == 2) {
      Abilities.emplace_back("Icebolt", 2u, 1u, ABILITYTARGET::ENEMY, 6u,
                             ABILITYSCALER::INT);
      MP->setMax(MP->getMax() + 2u);
      MP->increaseCurrent(1u);
      increaseStats(0, 1, 0);
    }
  }
};

class Warrior : public PlayerCharacterDelegate {
 public:
  static constexpr welltype BASEHP = static_cast<welltype>(18u);
  static constexpr welltype BASEMP = static_cast<welltype>(0u);
  static constexpr stattype BASESTR = static_cast<stattype>(6u);
  static constexpr stattype BASEINT = static_cast<stattype>(2u);
  static constexpr stattype BASEAGI = static_cast<stattype>(2u);

  Warrior() : PlayerCharacterDelegate() { PCCONSTRUCT }
  auto getClassName() -> std::string override { return "Warrior"; }

 private:
  void LevelUp() override {
    LEVELUP
    if (getLevel() == 2) {
      Abilities.emplace_back("PowerAttack", 0u, 3u, ABILITYTARGET::ENEMY, 4u,
                             ABILITYSCALER::STR);
    }
  }
};

class Rogue : public PlayerCharacterDelegate {
 public:
  static constexpr welltype BASEHP = static_cast<welltype>(12u);
  static constexpr welltype BASEMP = static_cast<welltype>(0u);
  static constexpr stattype BASESTR = static_cast<stattype>(3u);
  static constexpr stattype BASEINT = static_cast<stattype>(3u);
  static constexpr stattype BASEAGI = static_cast<stattype>(6u);

  Rogue() : PlayerCharacterDelegate() { PCCONSTRUCT }
  auto getClassName() -> std::string override { return "Rogue"; }

 private:
  void LevelUp() override {
    LEVELUP
    if (getLevel() == 2) {
      Abilities.emplace_back("PreciseAttack", 0u, 3u, ABILITYTARGET::ENEMY, 6u,
                             ABILITYSCALER::AGI);
    }
  }
};

// CHARACTERCLASS(Cleric, 14u, 3u, 5u, 1u)
// CHARACTERCLASS(Wizzard, 10u, 1u, 7u, 1u)
// CHARACTERCLASS(Warrior, 18u, 5u, 2u, 2u)
// CHARACTERCLASS(Rogue, 12u, 4u, 4u, 5u)
