#include <iostream>

#include "classes.hpp"
#include "hp.hpp"
#include "stattypes.hpp"

auto main() -> int {
  Warrior warr1;
  Wizard wiz1;
  Cleric cler1;
  Rogue rog1;

  // std::cout << "Warrior" << std::endl
  //           << "-MaxHP:" << static_cast<int>(warr1.getMaxHp()) << std::endl
  //           << "-Strength:" << static_cast<int>(warr1.getStrength())
  //           << std::endl
  //           << "-Intelligence:" << static_cast<int>(warr1.getInteligence())
  //           << std::endl;
  // std::cout << "Wizard" << std::endl
  //           << "-MaxHP:" << static_cast<int>(wiz1.getMaxHp()) << std::endl
  //           << "-Strength:" << static_cast<int>(wiz1.getStrength()) <<
  //           std::endl
  //           << "-Intelligence:" << static_cast<int>(wiz1.getInteligence())
  //           << std::endl;
  for (int i = 0; i < 2; i++) {
    std::cout << "Cleric Level " << cler1.getLevel() << '\n'
              << "-EXP: " << cler1.getCurrentEXP() << "/"
              << static_cast<int>(cler1.getEXPToNextLevel()) << '\n'
              << "-MaxHP: " << static_cast<int>(cler1.getMaxHp()) << '\n'
              << "-Stength: " << static_cast<int>(cler1.getStrength()) << '\n'
              << "-Intellect: " << static_cast<int>(cler1.getInteligence())
              << '\n';
    if (i < 1) cler1.gainExp(100u);
  }
  std::cout << "------------\n";
  for (int i = 0; i < 2; i++) {
    std::cout << "Rogue Level " << rog1.getLevel() << '\n'
              << "-EXP: " << rog1.getCurrentEXP() << "/"
              << static_cast<int>(rog1.getEXPToNextLevel()) << '\n'
              << "-MaxHP: " << static_cast<int>(rog1.getMaxHp()) << '\n'
              << "-Stength: " << static_cast<int>(rog1.getStrength()) << '\n'
              << "-Intellect: " << static_cast<int>(rog1.getInteligence())
              << '\n';
    if (i < 1) rog1.gainExp(100u);
  }
  std::cout << "------------\n";
  // std::cout << "Rogue" << std::endl
  //           << "-MaxHP:" << static_cast<int>(rog1.getMaxHp()) << std::endl
  //           << "-Strength:" << static_cast<int>(rog1.getStrength()) <<
  //           std::endl
  //           << "-Intelligence:" << static_cast<int>(rog1.getInteligence())
  //           << std::endl;
  return 0;
}