#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/spinach.hpp"

TEST_CASE( "it returns # when it is tilled soil" ) {
  Spinach spinach;
  REQUIRE( spinach.symbol() == "#" );
}

TEST_CASE( "it returns s when it is a seedling" ) {
  Spinach spinach;
  spinach.end_day();
  spinach.end_day();
  REQUIRE( spinach.symbol() == "s" );
}

TEST_CASE( "it returns S when the spinach is fully grown" ) {
  Spinach spinach;
  spinach.end_day();
  spinach.end_day();
  spinach.end_day();
  REQUIRE( spinach.symbol() == "S" );
}

TEST_CASE( "it is harvestable when fully grown" ) {
  Spinach spinach;
  spinach.end_day();
  spinach.end_day();
  spinach.end_day();
  REQUIRE( spinach.is_harvestable() == true );
}

TEST_CASE( "it is not harvestable when a seedling" ) {
  Spinach spinach;
  spinach.end_day();
  spinach.end_day();
  REQUIRE( spinach.is_harvestable() == false );
}

TEST_CASE( "it increases growth by 2 when watered" ) {
  Spinach spinach;
  spinach.water();
  spinach.end_day();
  REQUIRE( spinach.get_days() == 2 );
  spinach.end_day();
  REQUIRE( spinach.get_days() == 3 );
  REQUIRE( spinach.symbol() == "S" );
  REQUIRE( spinach.is_harvestable() == true );
}

