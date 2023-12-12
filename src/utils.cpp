#include "utils.hpp"

#include <cmath>
#include <sstream>
#include <algorithm>

/// Check if n of args is correct
auto checkArgs(const int &argc) noexcept -> bool {
  return argc >= 2;
}

/// Check if string is a number
auto isNumber(const std::string &str) noexcept -> bool {
  return !str.empty() && std::find_if(str.begin(), str.end(), [](char elem) { return std::isdigit(elem) == 0; }) == str.end();
}

/// Tokenize a string
auto tokenize(const std::string &str, const char &delimiter) noexcept -> std::vector<std::string> {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

/// Parse the expression
auto parseExp(Stack expStack, const std::vector<std::string> &tokens) -> std::string {
  double op1 = NAN;
  double op2 = NAN;
  for (auto const &token : tokens) {
    if (isNumber(token)) {
      expStack.push(std::stod(token));
    } else {
      if (token.find('+') != std::string::npos) {
        op1 = expStack.pop();
        op2 = expStack.pop();
        expStack.push(op1 + op2);
      } else if (token.find('-') != std::string::npos) {
        op1 = expStack.pop();
        op2 = expStack.pop();
        expStack.push(op2 - op1);
      } else if (token.find('x') != std::string::npos) {
        op1 = expStack.pop();
        op2 = expStack.pop();
        expStack.push(op1 * op2);
      } else if (token.find('/') != std::string::npos) {
        op1 = expStack.pop();
        op2 = expStack.pop();
        if (op1 == 0.0) {
          throw std::invalid_argument("Division by 0 is not possible!");
        }
        expStack.push((op2 / op1));

      }
    }
  }
  return std::to_string(expStack.pop());
}
