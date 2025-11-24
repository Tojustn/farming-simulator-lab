#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"

TEST_CASE( "it returns # when it is tilled soil" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "#" );
}

TEST_CASE( "it returns C when the carrot is fully grown" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.symbol() == "C" );
}

TEST_CASE( "it is harvestable when fully grown" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.is_harvestable() == true );
}

TEST_CASE( "it is not harvestable when tilled soil" ) {
  Carrot carrot;
  REQUIRE( carrot.is_harvestable() == false );
}

TEST_CASE( "it increases growth by 2 when watered" ) {
  Carrot carrot;
  carrot.water();
  carrot.end_day();
  REQUIRE( carrot.get_days() == 2 );
  REQUIRE( carrot.symbol() == "C" );
  REQUIRE( carrot.is_harvestable() == true );
}

TEST_CASE( "watering more than once per day has no effect" ) {
  Carrot carrot;
  carrot.water();
  carrot.water();
  carrot.end_day();
  REQUIRE( carrot.symbol() == "C" );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
  Carrot carrot;
  carrot.water();
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.is_harvestable() == true );
}
