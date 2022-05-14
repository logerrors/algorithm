#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__)
{
    auto s = std::make_shared<Solution>();

    SECTION("example1")
    {
        auto *root = leetcode::from_string<TreeNode>("[3,5,1,6,2,0,8,null,null,7,4]");
        auto *p = find(root, 5);
        auto *q = find(root, 1);
        auto *expect = find(root, 3);
        REQUIRE(s->lowestCommonAncestor(root, p, q) == expect);
    }

    SECTION("example2")
    {
        auto *root = leetcode::from_string<TreeNode>("[3,5,1,6,2,0,8,null,null,7,4]");
        auto *p = find(root, 5);
        auto *q = find(root, 4);
        auto *expect = find(root, 5);
        REQUIRE(s->lowestCommonAncestor(root, p, q) == expect);
    }

    SECTION("example3")
    {
        auto *root = leetcode::from_string<TreeNode>("[1,2]");
        auto *p = find(root, 1);
        auto *q = find(root, 2);
        auto *expect = find(root, 1);
        REQUIRE(s->lowestCommonAncestor(root, p, q) == expect);
    }
}