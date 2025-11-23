#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lettuce.hpp"

TEST_CASE( "it returns # when it is tilled soil" ) {
  Lettuce lettuce;
  REQUIRE( lettuce.symbol() == "#" );
}

TEST_CASE( "it returns l when it is a seedling" ) {
  Lettuce lettuce;
  lettuce.end_day();
  lettuce.end_day();
  REQUIRE( lettuce.symbol() == "l" );
}

TEST_CASE( "it returns L when the lettuce is fully grown" ) {
  Lettuce lettuce;
  lettuce.end_day();
  lettuce.end_day();
  lettuce.end_day();
  lettuce.end_day();
  REQUIRE( lettuce.symbol() == "L" );
}

TEST_CASE( "it is harvestable when fully grown" ) {
  Lettuce lettuce;
  lettuce.end_day();
  lettuce.end_day();
  lettuce.end_day();
  lettuce.end_day();
  REQUIRE( lettuce.is_harvestable() == true );
}

TEST_CASE( "it is not harvestable when a seedling" ) {
  Lettuce lettuce;
  lettuce.end_day();
  lettuce.end_day();
  REQUIRE( lettuce.is_harvestable() == false );
}

TEST_CASE( "it increases growth by 2 when watered" ) {
  Lettuce lettuce;
  lettuce.water();
  lettuce.end_day();
  REQUIRE( lettuce.get_days() == 2 );
  lettuce.end_day();
  REQUIRE( lettuce.get_days() == 3 );
  lettuce.end_day();
  REQUIRE( lettuce.get_days() == 4 );
  REQUIRE( lettuce.symbol() == "L" );
  REQUIRE( lettuce.is_harvestable() == true );
}

