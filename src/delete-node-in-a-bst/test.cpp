#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE(__FILE__){
    auto s = std::make_shared<Solution>();

    SECTION("example1"){
        auto test = leetcode::from_string<TreeNode>("[5,3,6,2,4,null,7]");
        auto expect = leetcode::from_string<TreeNode>("[5,4,6,2,null,null,7]");
        auto data = s->deleteNode(test, 3);
        REQUIRE(leetcode::equal(expect, data));
        destroy(test);
        destroy(expect);
    }

    SECTION("example2"){
        auto test = leetcode::from_string<TreeNode>("[5,3,6,2,4,null,7]");
        auto expect = leetcode::from_string<TreeNode>("[5,3,6,2,4,null,7]");
        auto data = s->deleteNode(test, 0);
        REQUIRE(leetcode::equal(expect, data));
        destroy(test);
        destroy(expect);
    }

    SECTION("example3"){
        auto test = leetcode::from_string<TreeNode>("[]");
        auto expect = leetcode::from_string<TreeNode>("[]");
        auto data = s->deleteNode(test, 0);
        REQUIRE(leetcode::equal(expect, data));
        destroy(test);
        destroy(expect);
    }
}