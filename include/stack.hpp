#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

/// A Stack class to parse an expression
class Stack {

public:
  auto pop() -> float;
  void push(float item);
private:
  std::vector<float> st;
};
