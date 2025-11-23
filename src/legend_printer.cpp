#include "legend_printer.hpp"

std::string LegendPrinter::pp() {
  std::string output = "";
  output += "=== LEGEND ===\n";
  output += "@  Player\n";
  output += ".  Soil\n";
  output += "#  Tilled soil\n";
  output += "v  Carrot (seedling)\n";
  output += "V  Carrot (growing)\n";
  output += "W  Carrot (ready)\n";
  output += "\n=== CONTROLS ===\n";
  output += "w  Move up\n";
  output += "a  Move left\n";
  output += "s  Move down\n";
  output += "d  Move right\n";
  output += "c  Plant carrot\n";
  output += "h  Harvest\n";
  output += "t  Water\n";
  output += "e  End day\n";
  output += "?  Show legend\n";
  output += "q  Quit\n";
  return output;
}