#pragma once
#include <cstdint>
#include <string>

enum class ABILITYTARGET { SELF, ALLY, ENEMY };
enum class ABILITYSCALER { NONE, STR, AGI, INT };

struct Ability {
  Ability(std::string n, std::uint8_t c, std::uint8_t _cd, ABILITYTARGET t,
          std::uint8_t hp_e_, ABILITYSCALER s)
      : name(std::move(n)),
        cost(c),
        cooldown(_cd),
        target(t),
        hp_effect(hp_e_),
        scalar(s) {}
  std::string name = "none";
  std::uint8_t cost = 0;
  std::uint8_t cooldown = 1;
  ABILITYTARGET target = ABILITYTARGET::SELF;
  ABILITYSCALER scalar = ABILITYSCALER::NONE;
  std::uint8_t hp_effect = 1;
};
