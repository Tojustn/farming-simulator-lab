#include <string>

#include "spinach.hpp"
#include "soil.hpp"

std::string Spinach::symbol() {
  if(days == 0) {
    return "#";
  } else if(days <= days_to_sprout) {
    return "s";
  } else {
    return "S";
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
  return days >= (days_to_sprout + days_to_maturity);
}

int Spinach::get_days() {
  return days;
}

