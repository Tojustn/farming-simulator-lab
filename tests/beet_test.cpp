#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/beet.hpp"

TEST_CASE( "it returns # when it is tilled soil" ) {
  Beet beet;
  REQUIRE( beet.symbol() == "#" );
}

TEST_CASE( "it returns b when it is a seedling" ) {
  Beet beet;
  beet.end_day();
  beet.end_day();
  REQUIRE( beet.symbol() == "b" );
}

TEST_CASE( "it returns B when the beet is fully grown" ) {
  Beet beet;
  beet.end_day();
  beet.end_day();
  beet.end_day();
  beet.end_day();
  beet.end_day();
  REQUIRE( beet.symbol() == "B" );
}

TEST_CASE( "it is harvestable when fully grown" ) {
  Beet beet;
  beet.end_day();
  beet.end_day();
  beet.end_day();
  beet.end_day();
  beet.end_day();
  REQUIRE( beet.is_harvestable() == true );
}

TEST_CASE( "it is not harvestable when a seedling" ) {
  Beet beet;
  beet.end_day();
  beet.end_day();
  REQUIRE( beet.is_harvestable() == false );
}

TEST_CASE( "it increases growth by 2 when watered" ) {
  Beet beet;
  beet.water();
  beet.end_day();
  REQUIRE( beet.get_days() == 2 );
  beet.end_day();
  REQUIRE( beet.get_days() == 3 );
  beet.end_day();
  REQUIRE( beet.get_days() == 4 );
  beet.end_day();
  REQUIRE( beet.get_days() == 5 );
  REQUIRE( beet.symbol() == "B" );
  REQUIRE( beet.is_harvestable() == true );
}

