#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

int guess(int num){
    int pick = 9;
    if(num > pick){
        return -1;
    }else if(num < pick){
        return 1;
    }else{
        return 0;
    }
}

TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("example1"){
        REQUIRE(s->guessNumber(10) == 9);
    }
}