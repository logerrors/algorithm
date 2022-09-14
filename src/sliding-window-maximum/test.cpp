#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();
    std::vector<int> q1 = {1,3,-1,-3,5,3,6,7};
    std::vector<int> a1 =  {3,3,5,5,6,7};
    REQUIRE(s->maxSlidingWindow(q1, 3) == a1);
}