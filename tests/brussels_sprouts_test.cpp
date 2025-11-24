#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/brussels_sprouts.hpp"

TEST_CASE( "it returns # when it is tilled soil" ) {
  BrusselsSprouts brussels;
  REQUIRE( brussels.symbol() == "#" );
}

TEST_CASE( "it returns r when it is a seedling" ) {
  BrusselsSprouts brussels;
  brussels.end_day();
  brussels.end_day();
  brussels.end_day();
  brussels.end_day();
  brussels.end_day();
  REQUIRE( brussels.symbol() == "r" );
}

TEST_CASE( "it returns R when the brussels sprouts is fully grown" ) {
  BrusselsSprouts brussels;
  for(int i = 0; i < 10; i++) {
    brussels.end_day();
  }
  REQUIRE( brussels.symbol() == "R" );
}

TEST_CASE( "it is harvestable when fully grown" ) {
  BrusselsSprouts brussels;
  for(int i = 0; i < 10; i++) {
    brussels.end_day();
  }
  REQUIRE( brussels.is_harvestable() == true );
}

TEST_CASE( "it is not harvestable when a seedling" ) {
  BrusselsSprouts brussels;
  brussels.end_day();
  brussels.end_day();
  brussels.end_day();
  brussels.end_day();
  brussels.end_day();
  REQUIRE( brussels.is_harvestable() == false );
}

TEST_CASE( "it increases growth by 2 when watered" ) {
  BrusselsSprouts brussels;
  brussels.water();
  brussels.end_day();
  REQUIRE( brussels.get_days() == 2 );
  brussels.end_day();
  REQUIRE( brussels.get_days() == 3 );
  brussels.end_day();
  REQUIRE( brussels.get_days() == 4 );
  brussels.end_day();
  REQUIRE( brussels.get_days() == 5 );
  brussels.end_day();
  REQUIRE( brussels.get_days() == 6 );
  brussels.end_day();
  REQUIRE( brussels.get_days() == 7 );
  brussels.end_day();
  REQUIRE( brussels.get_days() == 8 );
  brussels.end_day();
  REQUIRE( brussels.get_days() == 9 );
  brussels.end_day();
  REQUIRE( brussels.get_days() == 10 );
  REQUIRE( brussels.symbol() == "R" );
  REQUIRE( brussels.is_harvestable() == true );
}

