#include "solution.hpp"

using namespace leetcode;
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("Example 1"){
        std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        std::vector<std::vector<int>> expected = {{1,6},{8,10},{15,18}};
        REQUIRE(s->merge(intervals) == expected);
    }
}