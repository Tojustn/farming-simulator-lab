#include "legend_printer.hpp"

std::string LegendPrinter::pp() {
  std::string output = "";
  output += "=== LEGEND ===\n";
  output += "@  Player\n";
  output += ".  Soil\n";
  output += "#  Tilled soil\n";
  output += "c  Carrot (seedling)\n";
  output += "l  Lettuce (seedling)\n";
  output += "s  Spinach (seedling)\n";
  output += "b  Beet (seedling)\n";
  output += "r  Brussels Sprouts (seedling)\n";
  output += "C  Carrot (adult)\n";
  output += "L  Lettuce (adult)\n";
  output += "S  Spinach (adult)\n";
  output += "B  Beet (adult)\n";
  output += "R  Brussels Sprouts (adult)\n";
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