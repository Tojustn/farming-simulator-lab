#include <string>
#include "bunny.hpp"

Bunny::Bunny(int row, int column, int dir_row, int dir_col) 
  : current_row(row), current_column(column), 
    direction_row(dir_row), direction_column(dir_col),
    original_direction_row(dir_row), original_direction_column(dir_col),
    scared(false), scared_moves_remaining(0) {
}

int Bunny::get_row() {
  return current_row;
}

int Bunny::get_column() {
  return current_column;
}

std::string Bunny::get_symbol() {
  return "u";
}

void Bunny::set_direction(int dir_row, int dir_col) {
  direction_row = dir_row;
  direction_column = dir_col;
  // Update original direction if not scared
  if(!scared) {
    original_direction_row = dir_row;
    original_direction_column = dir_col;
  }
}

bool Bunny::is_scared() {
  return scared;
}

void Bunny::set_scared(int player_row, int player_column) {
  // Store original direction before changing it
  if(!scared) {
    original_direction_row = direction_row;
    original_direction_column = direction_column;
  }
  
  // Calculate direction away from player
  int row_diff = current_row - player_row;
  int col_diff = current_column - player_column;
  
  // Normalize to -1, 0, or 1
  int scared_dir_row = 0;
  int scared_dir_col = 0;
  
  if(row_diff > 0) {
    scared_dir_row = 1;  // Move down (away from player above)
  } else if(row_diff < 0) {
    scared_dir_row = -1;  // Move up (away from player below)
  }
  
  if(col_diff > 0) {
    scared_dir_col = 1;  // Move right (away from player on left)
  } else if(col_diff < 0) {
    scared_dir_col = -1;  // Move left (away from player on right)
  }
  
  // If directly horizontal or vertical, pick one direction
  if(scared_dir_row == 0 && scared_dir_col == 0) {
    // Player is on same spot (shouldn't happen, but handle it)
    scared_dir_row = 1;
    scared_dir_col = 0;
  } else if(scared_dir_row == 0) {
    // Horizontal only
    scared_dir_row = 0;
  } else if(scared_dir_col == 0) {
    // Vertical only
    scared_dir_col = 0;
  } else {
    // Diagonal - pick primary direction (prefer vertical)
    scared_dir_col = 0;
  }
  
  direction_row = scared_dir_row;
  direction_column = scared_dir_col;
  scared = true;
  scared_moves_remaining = 4;  // Run 4 squares away
}

void Bunny::set_position(int row, int column) {
  current_row = row;
  current_column = column;
}

void Bunny::move() {
  if(scared && scared_moves_remaining > 0) {
    // Scared movement: move 4 squares in one go (can move off map)
    current_row += direction_row * 4;
    current_column += direction_column * 4;
    scared_moves_remaining = 0;
    scared = false;
    // Restore original direction after scared movement
    direction_row = original_direction_row;
    direction_column = original_direction_column;
  } else {
    // Normal movement: one square
    current_row += direction_row;
    current_column += direction_column;
  }
}

