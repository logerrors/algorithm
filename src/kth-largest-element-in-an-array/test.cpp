#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__)
{
    auto s = make_shared<Solution>();

    SECTION("example1")
    {
        vector<int> data = {3, 2, 1, 5, 6, 4};
        int k = 2;

        REQUIRE(s->findKthLargest(data, 2) == 5);
    }

    SECTION("example2")
    {
        vector<int> data = {3,2,3,1,2,4,5,5,6};
        int k = 4;
        REQUIRE(s->findKthLargest(data, 4));
    }
}