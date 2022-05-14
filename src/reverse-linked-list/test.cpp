#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("example1"){
        auto* src = leetcode::from_random(10);
        auto* copy = leetcode::copy(src);
        auto* rev_src = s->reverseList(src);
        
        auto arr_src = leetcode::to_array(rev_src);
        auto arr_copy = leetcode::to_array(copy);

        std::reverse(arr_copy.begin(), arr_copy.end());

        REQUIRE(arr_src == arr_copy);

        leetcode::destroy(rev_src);
        leetcode::destroy(copy);
    }
}