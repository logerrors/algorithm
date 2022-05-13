#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("example1"){
        auto* src = leetcode::make(10);
        auto* copy = leetcode::copy(src);
        s->reverseList(src);
        
        auto arr_src = leetcode::to_array(src);
        auto arr_copy = leetcode::to_array(copy);

        REQUIRE(arr_src == arr_copy);

        leetcode::destory(src);
        leetcode::destory(copy);
    }
}