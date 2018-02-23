#ifndef CPPSTACK_UTILS_H
#define CPPSTACK_UTILS_H

#include "stack.h"
#include <string>

bool checkArgs(const int &argc) noexcept;
std::string parseExp(Stack exp_stack, std::vector<std::string> tokens);

#endif // CPPSTACK_UTILS_H
