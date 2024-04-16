//
// Created by Luca Francesca on 11/12/23.
//
#include <catch2/catch_test_macros.hpp>
#include <stack.hpp>
#include <utils.hpp>

TEST_CASE("Addition", "[add]") {
  Stack theStack;
  auto tokens = tokenize("5 12 +", ' ');
  auto res = parseExp(theStack, tokens);
  REQUIRE(res == "17.000000" );
}

TEST_CASE("Subtraction", "[sub]") {
  Stack theStack;
  auto tokens = tokenize("20 14 -", ' ');
  auto res = parseExp(theStack, tokens);
  REQUIRE(res == "6.000000" );
}

TEST_CASE("Multiplication", "[mlt]") {
  Stack theStack;
  auto tokens = tokenize("5 6 x", ' ');
  auto res = parseExp(theStack, tokens);
  REQUIRE(res == "30.000000" );
}

TEST_CASE("Division", "[div]") {
  Stack theStack;
  auto tokens = tokenize("100 4 /", ' ');
  auto res = parseExp(theStack, tokens);
  REQUIRE(res == "25.000000" );
}

TEST_CASE("Mixed", "[mix]") {
  Stack theStack;
  auto tokens = tokenize("5 10.5 x 2.6 / 2 + 4 -", ' ');
  auto res = parseExp(theStack, tokens);
  REQUIRE(res == "18.192308" );
}

// test parseExp with division by 0
TEST_CASE("Division by 0", "[div0]") {
  Stack theStack;
  checkArgs(2);
  auto tokens = tokenize("5 0 /", ' ');
  REQUIRE_THROWS_AS(parseExp(theStack, tokens), std::invalid_argument);
}

// test checkArgs
TEST_CASE("CheckArgs", "[checkArgs]") {
  REQUIRE(checkArgs(2) == true);
  REQUIRE(checkArgs(1) == false);
}