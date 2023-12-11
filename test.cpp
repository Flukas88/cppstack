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

TEST_CASE("Substraction", "[sub]") {
  Stack theStack;
  auto tokens = tokenize("20 14 -", ' ');
  auto res = parseExp(theStack, tokens);
  REQUIRE(res == "6.000000" );
}

TEST_CASE("Multiplicatipn", "[mult]") {
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
  auto tokens = tokenize("5 10 x 2 /", ' ');
  auto res = parseExp(theStack, tokens);
  REQUIRE(res == "25.000000" );
}

