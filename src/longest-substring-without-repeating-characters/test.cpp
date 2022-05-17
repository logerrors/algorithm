#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__)
{
    auto s = std::make_shared<Solution>();

    SECTION("example1")
    {
        auto input = "abcabcbb";
        auto output = 3;
        REQUIRE(s->lengthOfLongestSubstring(input) == output);
    }

    SECTION("example2")
    {
        auto input = "bbbbb";
        auto output = 1;
        REQUIRE(s->lengthOfLongestSubstring(input) == output);
    }

    SECTION("example3")
    {
        auto input = "pwwkew";
        auto output = 3;
        REQUIRE(s->lengthOfLongestSubstring(input) == output);
    }

    SECTION("example4"){
        auto input = " ";
        auto output = 1;
        REQUIRE(s->lengthOfLongestSubstring(input) == output);
    }
}