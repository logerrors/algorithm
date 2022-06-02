#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){
    auto s = std::make_unique<Solution>();
    SECTION("example1"){
        std::vector<int> arr = {0,1,0};
        REQUIRE(s->peakIndexInMountainArray(arr) == 1);
    }

    SECTION("example2"){
        std::vector<int> arr = {24,69,100,99,79,78,67,36,26,19};
        REQUIRE(s->peakIndexInMountainArray(arr) == 2);
    }
}