#include <string>

#include "beet.hpp"
#include "soil.hpp"

std::string Beet::symbol() {
  if (days < days_to_sprout) {
    return "#";
  } else if (days < days_to_sprout + days_to_maturity) {
    return "b";
  } else {
    return "B";
  }
}

void Beet::end_day() {
  if(watered) {
    days += 2;
  } else {
    days += 1;
  }
  watered = false;
}

void Beet::water() {
  watered = true;
}

bool Beet::is_harvestable() {
  return days >= (days_to_sprout + days_to_maturity);
}

int Beet::get_days() {
  return days;
}

