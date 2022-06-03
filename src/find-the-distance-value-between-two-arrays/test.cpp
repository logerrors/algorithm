#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){
    Solution s;
    std::vector<int> arr1 = {1,4,2,3};
    std::vector<int> arr2 = {-4,-3,6,10,20,30};
    REQUIRE(s.findTheDistanceValue(arr1, arr2, 3) == 2);
}