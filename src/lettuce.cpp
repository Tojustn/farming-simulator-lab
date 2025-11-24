#include <string>

#include "lettuce.hpp"
#include "soil.hpp"

std::string Lettuce::symbol() {
  if (days < days_to_sprout) {
    return "#";  // tilled/seed
  } else if (days >= days_to_maturity) {
    return "L";  // fully grown
  } else {
    return "l";  // sprouted but not mature
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
  return days >= days_to_maturity;
}

int Lettuce::get_days() {
  return days;
}

