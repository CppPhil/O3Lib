#define CATCH_CONFIG_MAIN
#include "Catch/Catch.hpp"
#include "O3/algorithm.h"
#include "O3/assert.h"
#include "O3/containers.h"
#include "O3/except.h"
#include "O3/final_act.h"
#include "O3/functional.h"
#include "O3/iterator.h"
#include "O3/macros.h"
#include "O3/noncopyable.h"
#include "O3/nullptr.h"
#include "O3/type_traits.h"
#include <deque>

namespace app {
    int f(int i, int j) {
        return i * j;
    }
}

SCENARIO("elements can be added to containers", "o3::push_back, push_front, insert") {
    GIVEN("A deque of ints") {
        std::deque<int> d;
        
        WHEN("elements are added at the end") {
            o3::push_back(d)(1)(2)(3)(4)(5);
            
            THEN("the size grows") {
                REQUIRE(d.size() == 5);
            }
            AND_THEN("the elements are added in order") {
                REQUIRE(d.at(0) == 1);
                REQUIRE(d.at(1) == 2);
                REQUIRE(d.at(2) == 3);
                REQUIRE(d.at(3) == 4);
                REQUIRE(d.at(4) == 5);
            }
        }
        AND_WHEN("elements are added at the front") {
            o3::push_front(d)(99)(50);
            
            THEN("the size grows") {
                REQUIRE(d.size() == 2);
            }
            AND_THEN("the elements are added in reverse order") {
                REQUIRE(d.at(0) == 50);
                REQUIRE(d.at(1) == 99);
            }
        }
        AND_WHEN("elements are added at an iterator") {
            o3::insert(d)(d.begin(), 5000);
            o3::insert(d)(d.begin() + 1, 200);
            o3::insert(d)(d.begin() + 1, 400);
            
            THEN("the size grows") {
                REQUIRE(d.size() == 3);
            }
            AND_THEN("the elements are added in reverse order at the iterator position") {
                REQUIRE(d.at(0) == 5000);
                REQUIRE(d.at(1) == 400);
                REQUIRE(d.at(2) == 200);
            }
        }
    }
}

SCENARIO("assertions can trigger", "assert.h") {
    GIVEN("a false boolean expression") {
        WHEN("an assertion is used on that false condition") {
            THEN("the assertion throws an exception") {
                REQUIRE_THROWS(O3_ASSERT(5 == 100));
                REQUIRE_THROWS(O3_CHECK_PRE(false));
                REQUIRE_THROWS(O3_CHECK_POST(false));
            }
        }
    }
    
    GIVEN("a true boolean expression") {
        WHEN("an assertion is used on a true condition") {
            THEN("the assertion does not throw") {
                REQUIRE_NOTHROW(O3_ASSERT(true));
                REQUIRE_NOTHROW(O3_CHECK_PRE(sizeof(char) == 1));
                REQUIRE_NOTHROW(O3_CHECK_POST(true));
            }
        }
    }
}

SCENARIO("arrays can be used", "containers.h") {
    GIVEN("an array") {
        o3::array<int, 5> a = { 1, 2, 3, 4, 5 };
        WHEN("the array is copied") {
            o3::array<int, 5> a2(a);
            THEN("the arrays are equal") {
                REQUIRE(a == a2);
                REQUIRE(a.at(0) == 1);
                REQUIRE(a.at(1) == 2);
                REQUIRE(a.at(2) == 3);
                REQUIRE(a.at(3) == 4);
                REQUIRE(a.at(4) == 5);
                REQUIRE(a2.at(0) == 1);
                REQUIRE(a2.at(1) == 2);
                REQUIRE(a2.at(2) == 3);
                REQUIRE(a2.at(3) == 4);
                REQUIRE(a2.at(4) == 5);
            }
        }
    }
}



