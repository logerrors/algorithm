#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("example1"){
        std::vector<int> t1 = {-1,0,3,5,9,12};
        REQUIRE(s->search(t1, 9) == 4);
    }

    SECTION("exmaple2"){
        std::vector<int> t2 = {-1,0,3,5,9,12};
        REQUIRE(s->search(t2, 2) == -1);
    }
}