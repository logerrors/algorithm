#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("example"){
        REQUIRE(s->mySqrt(4) == 2);
        REQUIRE(s->mySqrt(8) == 2);
    }
}