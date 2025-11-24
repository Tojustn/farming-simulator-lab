#include <string>

#include "carrot.hpp"
#include "soil.hpp"

std::string Carrot::symbol() {
  if (days < days_to_sprout) { 
      return "#"; 
  } else if (days < days_to_sprout + days_to_maturity) {
      return "c"; 
  } else {
    return "C";
  }
}

void Carrot::end_day() {
  if(watered) {
    days += 2;
  } else {
    days += 1;
  }
  watered = false;
}

void Carrot::water() {
  watered = true;
}

bool Carrot::is_harvestable() {
  return days >= days_to_maturity;
}

int Carrot::get_days() {
  return days;
}

