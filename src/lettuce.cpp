#include <string>

#include "lettuce.hpp"
#include "soil.hpp"

std::string Lettuce::symbol() {
  if(days == 0) {
    return "#";
  } else if(days <= days_to_sprout) {
    return "l";
  } else {
    return "L";
  }
}

void Lettuce::end_day() {
  if(watered) {
    days += 2;
  } else {
    days += 1;
  }
  watered = false;
}

void Lettuce::water() {
  watered = true;
}

bool Lettuce::is_harvestable() {
  return days >= (days_to_sprout + days_to_maturity);
}

int Lettuce::get_days() {
  return days;
}

