#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("example1"){
        auto node = leetcode::from_string<TreeNode>("[1,2,3]");
        REQUIRE(s->maxPathSum(node) == 6);
        destroy(node);
    }

    SECTION("example2"){
        auto node = leetcode::from_string<TreeNode>("[-10,9,20,null,null,15,7]");
        REQUIRE(s->maxPathSum(node) == 42);
    }
}