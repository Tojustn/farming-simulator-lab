#include <string>

#include "beet.hpp"
#include "soil.hpp"

std::string Beet::symbol() {
  if (days < days_to_sprout) {
    return "#";  // tilled/seed
  } else if (days >= days_to_maturity) {
    return "B";  // fully grown
  } else {
    return "b";  // sprouted but not mature
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
  return days >= days_to_maturity;
}

int Beet::get_days() {
  return days;
}

