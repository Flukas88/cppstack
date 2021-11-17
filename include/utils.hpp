#ifndef CPPSTACK_UTILS_HPP
#define CPPSTACK_UTILS_HPP

#include "stack.hpp"
#include <string>

bool checkArgs(const int &argc) noexcept;
std::string parseExp(Stack expStack, const std::vector<std::string>& tokens);
static bool isNumber(const std::string &s);
std::vector<std::string> tokenize(const std::string &text, char sep);


#endif // CPPSTACK_UTILS_HPP
