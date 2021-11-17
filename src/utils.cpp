#include "utils.hpp"

/// Check if n of args is correct
bool checkArgs(const int &argc) noexcept {
  return argc >= 2;
}

bool isNumber(const std::string &s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && isdigit(*it))
    ++it;
  return !s.empty() && it == s.end();
}

std::vector<std::string> tokenize(const std::string &text, char sep = ' ') {
  std::vector<std::string> tokens;
  std::size_t start = 0, end;
  while ((end = text.find(sep, start)) != std::string::npos) {
    tokens.push_back(text.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
  return tokens;
}

/// Parse the expression
std::string parseExp(Stack expStack, const std::vector<std::string> &tokens) {
  double op1, op2;
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
        } else {
          expStack.push((op2 / op1));
        }
      }
    }
  }
  return std::to_string(expStack.pop());
}