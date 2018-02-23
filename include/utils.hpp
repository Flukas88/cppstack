#ifndef CPPSTACK_UTILS_HPP
#define CPPSTACK_UTILS_HPP

#include "stack.hpp"
#include <string>

bool checkArgs(const int &argc) noexcept;
const std::string parseExp(Stack exp_stack, std::vector<std::string> tokens);

#endif // CPPSTACK_UTILS_HPP
