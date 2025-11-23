#include <iostream>

#include "src/legend_printer.hpp"
#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"

int main() {
  Player player;
  Farm farm(7, 8, &player);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;
  LegendPrinter legend_printer;

  // Show legend at start
  ansi_clear();
  std::cout << legend_printer.pp() << std::endl;
  std::cout << "Press any key to start..." << std::endl;
  std::cin >> player_input;

  while(game_in_progress) {
    ansi_clear();
    std::cout << printer.pp() << std::endl;
    std::cin >> player_input;

    if(player_input == "q") {
      game_in_progress = false;
    } else if(player_input == "w") {
      if(farm.is_valid_position(player.row() - 1, player.column())) {
        player.move_up();
      }
    } else if(player_input == "a") {
      if(farm.is_valid_position(player.row(), player.column() - 1)) {
        player.move_left();
      }
    } else if(player_input == "d") {
      if(farm.is_valid_position(player.row(), player.column() + 1)) {
        player.move_right();
      }
    } else if(player_input == "s") {
      if(farm.is_valid_position(player.row() + 1, player.column())) {
        player.move_down();
      }
    } else if(player_input == "c") {
      Carrot *carrot = new Carrot();
      farm.plant(player.row(), player.column(), carrot);
    } else if(player_input == "h") {
      farm.harvest(player.row(), player.column());
    } else if(player_input == "t") {
      farm.water(player.row(), player.column());
    } else if(player_input == "e") {
      farm.end_day();
    } else if(player_input == "?") {
      ansi_clear();
      std::cout << legend_printer.pp() << std::endl;
      std::cout << "Press any key to continue..." << std::endl;
      std::cin >> player_input;
    }
  }
}
