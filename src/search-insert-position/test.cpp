#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){
    Solution s;
    std::vector<int> nums{1,3,5,6};
    REQUIRE(s.searchInsert(nums, 5) == 2);
    REQUIRE(s.searchInsert(nums, 2) == 1);
    REQUIRE(s.searchInsert(nums, 7) == 4);
    REQUIRE(s.searchInsert(nums, 0) == 0);
}