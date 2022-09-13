#include "solution.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__)
{
    auto s = std::make_shared<Solution>();
    
    REQUIRE(s->longestPalindrome("babad") == "bab");
}