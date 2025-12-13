#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"
#include "bunny.hpp"

class Farm {
  private:
    int rows;
    int columns;
    Player *player;
    std::vector<std::vector<Plot *>> plots;
    std::vector<Bunny *> bunnies;
    int day = 0;
    bool bunny_spawn = true;

  public:
    Farm(int rows, int columns, Player *player);
    int number_of_rows();
    int number_of_columns();
    std::string get_symbol(int row, int column);
    void water(int row, int column);
    void plant(int row, int column, Plot *plot);
    void harvest(int row, int column);
    void start_day();
    void end_day();
    int get_day();
    bool is_valid_position(int row, int column);
    bool has_bunny_at(int row, int column);
    void check_player_proximity();
    void spawn_bunny();
    int get_bunny_count();
    bool get_bunny_spawn();
    void set_bunny_spawn(bool enabled);
    ~Farm();
};
