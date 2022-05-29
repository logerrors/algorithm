#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("example1"){
        int n = 2;
        std::vector<std::vector<int>> arr = {{1,0}};
        REQUIRE(s->canFinish(n, arr) == true);
    }

    SECTION("example2"){
        int n = 2;
        std::vector<std::vector<int>> arr = {{1,0},{0,1}};
        REQUIRE(s->canFinish(n, arr) == false);
    }
}