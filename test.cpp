#include <stack.hpp>
#include <utils.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("testing '5 10 x 2 /'") {
    Stack testStack;
    auto testTokens = tokenize("5 10 x 2 /", ' ');
    auto res = parseExp(testStack, testTokens);
    CHECK(res== "25.000000");
}