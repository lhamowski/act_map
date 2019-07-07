#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "act/map.hpp"

TEST_CASE("Creating simple map", "map")
{
    act::map m{std::pair{'a', 10}, std::pair{'b', 12}, std::pair{'c', -13}};

    REQUIRE(m.size() == 3);
}