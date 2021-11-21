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


TEST_CASE("testing '8 2 5 x + 1 3 2 x + 4 - /'") {
    Stack testStack;
    auto testTokens = tokenize("8 2 5 x + 1 3 2 x + 4 - /", ' ');
    auto res = parseExp(testStack, testTokens);

    CHECK(res== "6.000000");
}


TEST_CASE("testing '5 1 2 + 4 x + 3 - 2 /'") {
    Stack testStack;
    auto testTokens = tokenize("5 1 2 + 4 x + 3 - 2 /", ' ');
    auto res = parseExp(testStack, testTokens);

    CHECK(res== "7.000000");
}