#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

/// A Stack class to parse an expression
class Stack {

public:
  auto pop() -> double;
  void push(double item);
private:
  std::vector<double> st;
};
