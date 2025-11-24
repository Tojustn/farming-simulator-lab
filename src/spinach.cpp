#include <string>

#include "spinach.hpp"
#include "soil.hpp"

std::string Spinach::symbol() {
  if (days < days_to_sprout) {
    return "#";  // tilled/seed
  } else if (days >= days_to_maturity) {
    return "S";  // fully grown
  } else {
    return "s";  // sprouted but not mature
  }
}

void Spinach::end_day() {
  if(watered) {
    days += 2;
  } else {
    days += 1;
  }
  watered = false;
}

void Spinach::water() {
  watered = true;
}

bool Spinach::is_harvestable() {
  return days >= days_to_maturity;
}

int Spinach::get_days() {
  return days;
}

