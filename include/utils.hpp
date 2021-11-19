#ifndef CPPSTACK_UTILS_HPP
#define CPPSTACK_UTILS_HPP

#include "stack.hpp"
#include <string>

bool checkArgs(const int &argc) noexcept;
std::string parseExp(Stack expStack, const std::vector<std::string>& tokens);
static bool isNumber(const std::string &s) noexcept;
std::vector<std::string> tokenize(const std::string &str, const char &delimiter) noexcept ;


#endif // CPPSTACK_UTILS_HPP
