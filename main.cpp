#include <iostream>

#include "classes.hpp"
#include "hp.hpp"
#include "stattypes.hpp"

auto main() -> int {
  Warrior warr1;
  Wizard wiz1;
  Cleric cler1;
  Rogue rog1;

  std::cout << "Warrior" << std::endl
            << "-MaxHP:" << static_cast<int>(warr1.getMaxHp()) << std::endl
            << "-Strength:" << static_cast<int>(warr1.getStrength())
            << std::endl
            << "-Intelligence:" << static_cast<int>(warr1.getInteligence())
            << std::endl;
  std::cout << "Wizard" << std::endl
            << "-MaxHP:" << static_cast<int>(wiz1.getMaxHp()) << std::endl
            << "-Strength:" << static_cast<int>(wiz1.getStrength()) << std::endl
            << "-Intelligence:" << static_cast<int>(wiz1.getInteligence())
            << std::endl;
  std::cout << "Cleric" << std::endl
            << "-MaxHP:" << static_cast<int>(cler1.getMaxHp()) << std::endl
            << "-Strength:" << static_cast<int>(cler1.getStrength())
            << std::endl
            << "-Intelligence:" << static_cast<int>(cler1.getInteligence())
            << std::endl;
  std::cout << "Rogue" << std::endl
            << "-MaxHP:" << static_cast<int>(rog1.getMaxHp()) << std::endl
            << "-Strength:" << static_cast<int>(rog1.getStrength()) << std::endl
            << "-Intelligence:" << static_cast<int>(rog1.getInteligence())
            << std::endl;
  return 0;
}