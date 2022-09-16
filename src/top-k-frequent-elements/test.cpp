#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();
    std::vector a = {1,2};
    std::vector q = {1,1,1,2,2,3};
    REQUIRE(s->topKFrequent(q, 2) == a);
}