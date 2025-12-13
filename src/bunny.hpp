#pragma once

#include <string>

class Bunny {
  private:
    int current_row;
    int current_column;
    int direction_row;  // -1 for up, 1 for down, 0 for horizontal
    int direction_column;  // -1 for left, 1 for right, 0 for vertical
    int original_direction_row;  // Store original direction before scared
    int original_direction_column;
    bool scared;
    int scared_moves_remaining;  

  public:
    Bunny(int row, int column, int dir_row, int dir_col);
    int get_row();
    int get_column();
    void move();
    void set_scared(int player_row, int player_column);
    bool is_scared();
    std::string get_symbol();
    void set_direction(int dir_row, int dir_col);
    void set_position(int row, int column);
};

