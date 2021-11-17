#ifndef CPPSTACK_STACK_HPP
#define CPPSTACK_STACK_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

/// A Stack class to parse an expression
class Stack {

public:
  double pop();
  void push(double item);
private:
  std::vector<double> st;
};

#endif // CPPSTACK_STACK_HPP
