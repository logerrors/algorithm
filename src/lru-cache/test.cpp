#include "solution.hpp"
#include <memory>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE(__FILE__){
    SECTION("example1"){
       auto s = std::make_shared<LRUCache>(2);
       s->put(1, 1);
       s->put(2, 2);
       REQUIRE(s->get(1) == 1);
       s->put(3, 3);
       REQUIRE(s->get(2) == -1);
       s->put(4, 4);
       REQUIRE(s->get(1) == -1);
       REQUIRE(s->get(3) == 3);
       REQUIRE(s->get(4) == 4);
    }

    SECTION("example2"){
       auto s = std::make_shared<LRUCache>(2);
       s->put(2, 1);
       s->put(1, 1);
       s->put(2, 3);
       s->put(4, 1);
       REQUIRE(s->get(1) == -1);
       REQUIRE(s->get(2) == 3);
    }


}
