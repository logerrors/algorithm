#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__)
{
    auto s = std::make_shared<Solution>();

    SECTION("example1")
    {
        std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        REQUIRE(s->maxSubArray(nums) == 6);
    }

    SECTION("exmaple2")
    {
        std::vector<int> nums{1};
        REQUIRE(s->maxSubArray(nums) == 1);
    }

    SECTION("example3")
    {
        std::vector<int> nums{5, 4, -1, 7, 8};
        REQUIRE(s->maxSubArray(nums) == 23);
    }
}