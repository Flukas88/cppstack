//
// Created by lfrances on 26-Jul-17.
//

#ifndef CPPSTACK_STACK_H
#define CPPSTACK_STACK_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Stack {

public:
  double pop();
  void push(double item);
  bool is_number(const std::string &s);
  std::vector<std::string> split(const std::string &text, char sep);

private:
  std::vector<double> st;
};

std::string parseExp(Stack exp_stack, std::vector<std::string> tokens);

std::vector<std::string> Stack::split(const std::string &text, char sep = ' ') {
  std::vector<std::string> tokens;
  std::size_t start = 0, end = 0;
  while ((end = text.find(sep, start)) != std::string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
  return tokens;
}

void Stack::push(double item) { st.push_back(item); }

double Stack::pop() {
  double item;
  item = st.back();
  st.pop_back();
  return (item);
}

bool Stack::is_number(const std::string &s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it))
    ++it;
  return !s.empty() && it == s.end();
}

std::string parseExp(Stack exp_stack, std::vector<std::string> tokens) {
  double op1, op2;
  for (auto const &token : tokens) {
    if (exp_stack.is_number(token)) {
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
        if ((op1 == 0.0) || (op2 == 0.0)) {
          throw std::invalid_argument("Division by 0 is not possible!");
        } else {
          exp_stack.push((op2 / op1));
        }
      }
    }
  }
  return std::to_string(exp_stack.pop());
}

#endif // CPPSTACK_STACK_H
