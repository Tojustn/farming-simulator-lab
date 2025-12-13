#include <string>

#include "farm.hpp"
#include "farm_printer.hpp"

FarmPrinter::FarmPrinter(Farm *farm) : farm(farm) {}

std::string FarmPrinter::pp() {

  std::string output = "";
  output += "Day " + std::to_string(farm->get_day()) + "\n";
  output += "Bunnies: " + std::to_string(farm->get_bunny_count()) + "\n";
  for(int i = 0; i < farm->number_of_rows(); i++) {
    for(int j = 0; j < farm->number_of_columns(); j++) {
      output += farm-> get_symbol(i, j);
      output += " ";
    }
    output += "\n";
  }
  return output;
}
