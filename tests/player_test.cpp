#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"

TEST_CASE( "it starts the player in row zero, column zero" ) {
  Player player;
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player to the right" ) {
  Player player;
  player.move_right();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 1 );
}

TEST_CASE( "it moves the player down" ) {
  Player player;
  player.move_down();
  REQUIRE( player.row() == 1 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it moves the player left" ) {
  Player player;
  player.move_right();
  player.move_right();
  player.move_left();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 1 );
}

TEST_CASE( "it moves the player up" ) {
  Player player;
  player.move_down();
  player.move_down();
  player.move_up();
  REQUIRE( player.row() == 1 );
  REQUIRE( player.column() == 0 );
}

TEST_CASE( "it can move in multiple directions" ) {
  Player player;
  player.move_right();
  player.move_down();
  player.move_right();
  player.move_up();
  REQUIRE( player.row() == 0 );
  REQUIRE( player.column() == 2 );
}

TEST_CASE( "farm validates positions within bounds" ) {
  Player player;
  Farm farm(5, 7, &player);
  farm.set_bunny_spawn(false);
  REQUIRE( farm.is_valid_position(0, 0) == true );
  REQUIRE( farm.is_valid_position(4, 6) == true );
  REQUIRE( farm.is_valid_position(2, 3) == true );
}

TEST_CASE( "farm rejects positions out of bounds" ) {
  Player player;
  Farm farm(5, 7, &player);
  farm.set_bunny_spawn(false);
  REQUIRE( farm.is_valid_position(-1, 0) == false );
  REQUIRE( farm.is_valid_position(0, -1) == false );
  REQUIRE( farm.is_valid_position(5, 0) == false );
  REQUIRE( farm.is_valid_position(0, 7) == false );
  REQUIRE( farm.is_valid_position(-1, -1) == false );
  REQUIRE( farm.is_valid_position(10, 10) == false );
}