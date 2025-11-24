#include <string>

#include "brussels_sprouts.hpp"
#include "soil.hpp"

std::string BrusselsSprouts::symbol() {
  if (days < days_to_sprout) {
    return "#";
  } else if (days < days_to_sprout + days_to_maturity) {
    return "r";
  } else {
    return "R";
  }
}

void BrusselsSprouts::end_day() {
  if(watered) {
    days += 2;
  } else {
    days += 1;
  }
  watered = false;
}

void BrusselsSprouts::water() {
  watered = true;
}

bool BrusselsSprouts::is_harvestable() {
  return days >= (days_to_sprout + days_to_maturity);
}

int BrusselsSprouts::get_days() {
  return days;
}

