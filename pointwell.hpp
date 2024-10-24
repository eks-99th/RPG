#pragma once
#include "hitpointtypes.hpp"

class PointWell {
 private:
  welltype CurrentFullness;
  welltype Max;

 public:
  auto setMax(welltype new_max_) -> bool;
  auto getMax() -> welltype;
  auto getCurrent() -> welltype;
  void reduceCurrent(welltype damage);
  void increaseCurrent(welltype amount);
  PointWell();
  PointWell(welltype c, welltype m) {
    CurrentFullness = c;
    Max = m;
    if (CurrentFullness > Max) CurrentFullness = Max;
  }
};

PointWell::PointWell() {
  CurrentFullness = 1;
  Max = 1;
}

auto PointWell::setMax(welltype new_max) -> bool {
  if (new_max < 1) {
    return false;
  }
  Max = new_max;
  if (CurrentFullness > Max) {
    CurrentFullness = Max;
  }
  return true;
}

auto PointWell::getMax() -> welltype { return Max; }

auto PointWell::getCurrent() -> welltype { return CurrentFullness; }

void PointWell::reduceCurrent(welltype damage) {
  if (damage > CurrentFullness) {
    CurrentFullness = 0;
  } else {
    CurrentFullness -= damage;
  }
}

void PointWell::increaseCurrent(welltype amount) {
  if (CurrentFullness + amount > Max) {
    CurrentFullness = Max;
  } else {
    CurrentFullness += amount;
  }
}