#include "legend_printer.hpp"

std::string LegendPrinter::pp() {
  std::string output = "";
  output += "=== LEGEND ===\n";
  output += "@  Player\n";
  output += ".  Soil\n";
  output += "#  Tilled soil (all vegetables)\n";
  output += "\nVegetable Growth Stages:\n";
  output += "Carrot:          # -> c -> C\n";
  output += "Lettuce:         # -> l -> L\n";
  output += "Spinach:         # -> s -> S\n";
  output += "Beet:            # -> b -> B\n";
  output += "Brussels Sprouts: # -> r -> R\n";
  output += "\n=== CONTROLS ===\n";
  output += "w  Move up\n";
  output += "a  Move left\n";
  output += "s  Move down\n";
  output += "d  Move right\n";
  output += "c  Plant carrot\n";
  output += "l  Plant lettuce\n";
  output += "p  Plant spinach\n";
  output += "b  Plant beet\n";
  output += "r  Plant brussels sprouts\n";
  output += "h  Harvest\n";
  output += "t  Water\n";
  output += "e  End day\n";
  output += "?  Show legend\n";
  output += "q  Quit\n";
  return output;
}