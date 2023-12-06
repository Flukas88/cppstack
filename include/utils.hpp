#pragma once

#include "stack.hpp"
#include <string>

auto checkArgs(const int &argc) noexcept -> bool;
auto parseExp(Stack expStack, const std::vector<std::string>& tokens) -> std::string;
static auto isNumber(const std::string &elem) noexcept -> bool;
auto tokenize(const std::string &str, const char &delimiter) noexcept -> std::vector<std::string> ;

