#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.hpp"


TEST_CASE( "it returns a v as its symbol when it is a seedling" ) {
    Carrot carrot;
    REQUIRE( carrot.symbol() == "v" );
}

TEST_CASE( "carrot starts with age 0" ) {
    Carrot carrot;
    REQUIRE( carrot.get_age() == 0 );
}

TEST_CASE( "carrot symbol becomes V when mature (age > 0 and age < 2)" ) {
    Carrot carrot;
    carrot.end_day();
    REQUIRE( carrot.symbol() == "V" );
}

TEST_CASE( "carrot age increments after end_day" ) {
    Carrot carrot;
    REQUIRE( carrot.get_age() == 0 );

    carrot.end_day();
    REQUIRE( carrot.get_age() == 1 );

    carrot.end_day();
    REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "carrot evolves into final evolution" ) {
    Carrot carrot;
    carrot.end_day();
    carrot.end_day();

    REQUIRE( carrot.symbol() == "W" );
    REQUIRE( carrot.get_age() == 2 );
}