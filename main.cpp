#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"

void print_controls() {
    std::cout << "=== FARM GAME CONTROLS ===" << std::endl;
    std::cout << "Movement:" << std::endl;
    std::cout << "  w - Move Up" << std::endl;
    std::cout << "  a - Move Left" << std::endl;
    std::cout << "  s - Move Down" << std::endl;
    std::cout << "  d - Move Right" << std::endl;
    std::cout << "\nActions:" << std::endl;
    std::cout << "  c - Plant Carrot" << std::endl;
    std::cout << "  h - Harvest Crop" << std::endl;
    std::cout << "  n - Next Day" << std::endl;
    std::cout << "\nOther:" << std::endl;
    std::cout << "  q - Quit Game" << std::endl;
    std::cout << "==========================" << std::endl << std::endl;
}

int main() {
    Player player;
    int farm_rows{7};
    int farm_columns{8};
    Farm farm(farm_rows, farm_columns, &player);
    FarmPrinter printer(&farm);
    bool game_in_progress = true;
    std::string player_input;

    // Show controls at the start
    print_controls();
    std::cout << "Press Enter to start...";
    std::cin.ignore();

    while(game_in_progress) {
        ansi_clear();
        std::cout << printer.pp() << std::endl;
        std::cout << "\nEnter command (or '?' for help): ";
        std::cin >> player_input;

        if(player_input == "q") {
            game_in_progress = false;
        } else if(player_input == "?") {
            print_controls();
            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        } else if(player_input == "d") {
            player.move_right(farm_columns);
        } else if(player_input == "s") {
            player.move_down(farm_rows);
        } else if (player_input == "w") {
            player.move_up();
        } else if (player_input == "a") {
            player.move_left();
        } else if(player_input == "c") {
            Carrot *carrot = new Carrot();
            farm.plant(player.row(), player.column(), carrot);
        } else if (player_input =="h") {
            farm.harvest(player.row(), player.column());
        }
        else if (player_input == "n") {
            farm.next_day();
        }
    }
}