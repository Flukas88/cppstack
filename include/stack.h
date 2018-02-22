#ifndef CPPSTACK_STACK_H
#define CPPSTACK_STACK_H

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


#endif // CPPSTACK_STACK_H
