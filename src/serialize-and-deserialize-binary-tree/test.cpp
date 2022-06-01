#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE(__FILE__){
    auto s = std::make_shared<Codec>();

    SECTION("example1"){
        std::string str = "[1,2,3,null,null,4,5,null,null,null,null]";
        TreeNode* node = leetcode::from_string<TreeNode>(str);
        REQUIRE(str == leetcode::to_string<TreeNode>(node));
        // REQUIRE(s->serialize(node) == "[1,2,3,null,null,4,5]");
    }
}