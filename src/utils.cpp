//===-- src/utils.cpp - Utils functions implementation ---------------*- C++
//-*-===//
///
/// \file
/// This file contains the implementation for the utils functions
///
//===--------------------------------------------------------------------------===//
#include "utils.hpp"

/// Check if n of args is correct
bool checkArgs(const int &argc) noexcept {
  return argc >= 2;
}

/// Parse the expression
std::string parseExp(Stack exp_stack, const std::vector<std::string> &tokens) {
  double op1, op2 = double();
  for (auto const &token : tokens) {
    if (Stack::is_number(token)) {
      exp_stack.push(std::stod(token));
    } else {
      if (token.find('+') != std::string::npos) {
        op1 = exp_stack.pop();
        op2 = exp_stack.pop();
        exp_stack.push(op1 + op2);
      } else if (token.find('-') != std::string::npos) {
        op1 = exp_stack.pop();
        op2 = exp_stack.pop();
        exp_stack.push(op2 - op1);
      } else if (token.find('x') != std::string::npos) {
        op1 = exp_stack.pop();
        op2 = exp_stack.pop();
        exp_stack.push(op1 * op2);
      } else if (token.find('/') != std::string::npos) {
        op1 = exp_stack.pop();
        op2 = exp_stack.pop();
        if (op1 == 0.0) {
          throw std::invalid_argument("Division by 0 is not possible!");
        } else {
          exp_stack.push((op2 / op1));
        }
      }
    }
  }
  return std::to_string(exp_stack.pop());
}