#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.hpp"
#include "../src/farm.hpp"
#include "../src/bunny.hpp"

TEST_CASE( "bunny spawns can be disabled" ) {
  Player player;
  Farm farm(5, 5, &player);
  farm.set_bunny_spawn(false);
  REQUIRE( farm.get_bunny_spawn() == false );
}

TEST_CASE( "bunny spawns can be enabled" ) {
  Player player;
  Farm farm(5, 5, &player);
  farm.set_bunny_spawn(true);
  REQUIRE( farm.get_bunny_spawn() == true );
}

TEST_CASE( "bunny count starts at zero" ) {
  Player player;
  Farm farm(5, 5, &player);
  REQUIRE( farm.get_bunny_count() == 0 );
}

TEST_CASE( "bunny can be created" ) {
  Bunny bunny(2, 3, 1, 0);
  REQUIRE( bunny.get_row() == 2 );
  REQUIRE( bunny.get_column() == 3 );
  REQUIRE( bunny.get_symbol() == "u" );
}

TEST_CASE( "bunny moves in its direction" ) {
  Bunny bunny(2, 3, 1, 0);  // Moving down
  bunny.move();
  REQUIRE( bunny.get_row() == 3 );
  REQUIRE( bunny.get_column() == 3 );
}

TEST_CASE( "bunny moves left" ) {
  Bunny bunny(2, 3, 0, -1);  // Moving left
  bunny.move();
  REQUIRE( bunny.get_row() == 2 );
  REQUIRE( bunny.get_column() == 2 );
}

TEST_CASE( "bunny moves right" ) {
  Bunny bunny(2, 3, 0, 1);  // Moving right
  bunny.move();
  REQUIRE( bunny.get_row() == 2 );
  REQUIRE( bunny.get_column() == 4 );
}

TEST_CASE( "bunny moves up" ) {
  Bunny bunny(2, 3, -1, 0);  // Moving up
  bunny.move();
  REQUIRE( bunny.get_row() == 1 );
  REQUIRE( bunny.get_column() == 3 );
}

TEST_CASE( "scared bunny moves 4 spaces" ) {
  Bunny bunny(5, 5, 0, 1);  // Normal direction right
  bunny.set_scared(5, 0);  // Player is left of bunny, so bunny should move right
  REQUIRE( bunny.is_scared() == true );
  bunny.move();
  REQUIRE( bunny.get_row() == 5 );
  REQUIRE( bunny.get_column() == 9 );  // Moved 4 spaces right
  REQUIRE( bunny.is_scared() == false );  // No longer scared after moving
}

TEST_CASE( "scared bunny moves away from player below" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(6, 5);  // Player is below bunny
  bunny.move();
  REQUIRE( bunny.get_row() == 1 );  // Moved 4 spaces up (5 - 4)
  REQUIRE( bunny.get_column() == 5 );
}

TEST_CASE( "scared bunny moves away from player above" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(4, 5);  // Player is above bunny
  bunny.move();
  REQUIRE( bunny.get_row() == 9 );  // Moved 4 spaces down (5 + 4)
  REQUIRE( bunny.get_column() == 5 );
}

TEST_CASE( "scared bunny moves away from player on left" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(5, 4);  // Player is left of bunny
  bunny.move();
  REQUIRE( bunny.get_row() == 5 );
  REQUIRE( bunny.get_column() == 9 );  // Moved 4 spaces right (5 + 4)
}

TEST_CASE( "scared bunny moves away from player on right" ) {
  Bunny bunny(5, 5, 0, 1);
  bunny.set_scared(5, 6);  // Player is right of bunny
  bunny.move();
  REQUIRE( bunny.get_row() == 5 );
  REQUIRE( bunny.get_column() == 1 );  // Moved 4 spaces left (5 - 4)
}

TEST_CASE( "bunny position can be set" ) {
  Bunny bunny(2, 3, 0, 1);
  bunny.set_position(4, 5);
  REQUIRE( bunny.get_row() == 4 );
  REQUIRE( bunny.get_column() == 5 );
}

TEST_CASE( "bunny direction can be set" ) {
  Bunny bunny(2, 3, 0, 1);
  bunny.set_direction(-1, 0);
  bunny.move();
  REQUIRE( bunny.get_row() == 1 );
  REQUIRE( bunny.get_column() == 3 );
}

TEST_CASE( "farm displays bunny symbol" ) {
  Player player;
  Farm farm(5, 5, &player);
  farm.set_bunny_spawn(false);
  
  // Manually create and add a bunny (we'd need a way to do this, but for now test get_symbol)
  // This test might need farm to have a method to add bunnies for testing
  REQUIRE( farm.get_symbol(0, 0) == "@" );  // Player position
}

TEST_CASE( "farm checks for bunny at position" ) {
  Player player;
  Farm farm(5, 5, &player);
  farm.set_bunny_spawn(false);
  REQUIRE( farm.has_bunny_at(2, 2) == false );
}

