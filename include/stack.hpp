//===-- include/stack.hpp - Stack class definition ---------------*- C++
//-*-===//
///
/// \file
/// This file contains the definitions for the Stack class
///
//===----------------------------------------------------------------------===//

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
  static bool is_number(const std::string &s);
  static std::vector<std::string> split(const std::string &text, char sep);

private:
  std::vector<double> st;
};

#endif // CPPSTACK_STACK_HPP
