#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){

    SECTION("treenode copy"){
        auto s1 = leetcode::from_string<TreeNode>("[-10,9,20,null,null,15,7]");
        auto s2 = leetcode::copy(s1);

        REQUIRE(leetcode::equal(s1, s2));
        REQUIRE(s1 != s2);
        REQUIRE(s1->val == s2->val);
    }
}