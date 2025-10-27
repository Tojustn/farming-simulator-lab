#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>


#include "../src/farm.hpp"

#include "../src/farm_printer.hpp"
#include "../src/player.hpp"


TEST_CASE( "it pretty prints a single plot of land" ) {
    Player player;
    Farm farm(1, 1, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "\nDay: 1\n@ \n" );
}

TEST_CASE( "it pretty prints a 1x2 farm" ) {
    Player player;
    Farm farm(1, 2, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "\nDay: 1\n@ . \n" );
}

TEST_CASE( "it pretty prints a 2x1 farm" ) {
    Player player;
    Farm farm(2, 1, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "\nDay: 1\n@ \n. \n" );
}

TEST_CASE( "it pretty prints a 2x2 farm" ) {
    Player player;
    Farm farm(2, 2, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "\nDay: 1\n@ . \n. . \n" );
}

TEST_CASE( "it pretty prints a 3x3 farm" ) {
    Player player;
    Farm farm(3, 3, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "\nDay: 1\n@ . . \n. . . \n. . . \n" );
}

TEST_CASE( "it shows day 2 after next_day" ) {
    Player player;
    Farm farm(2, 2, &player);
    FarmPrinter printer(&farm);
    farm.next_day();
    REQUIRE( printer.pp() == "\nDay: 2\n@ . \n. . \n" );
}

TEST_CASE( "it shows day 3 after two next_days" ) {
    Player player;
    Farm farm(1, 1, &player);
    FarmPrinter printer(&farm);
    farm.next_day();
    farm.next_day();
    REQUIRE( printer.pp() == "\nDay: 3\n@ \n" );
}