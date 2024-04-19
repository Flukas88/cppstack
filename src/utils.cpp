#include "utils.hpp"

#include <cmath>
#include <sstream>

/// Check if n of args is correct
auto checkArgs(const int &argc) noexcept -> bool {
  return argc >= 2;
}

auto isNumber(const std::string &str) noexcept -> bool{
  std::istringstream iss(str);
  float f;
  iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
  return iss.eof() && !iss.fail();
}

/// Tokenize a string
auto tokenize(const std::string &str,
              const char &delimiter) noexcept -> std::vector<std::string> {
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
  float op1 = NAN;
  float op2 = NAN;
  for (auto const &token : tokens) {
    if (isNumber(token)) {
      // LOG(INFO) << "Pushing number " << token << '\n';
      expStack.push(std::stof(token));
    } else {
      if (token.find('+') != std::string::npos) {
        op1 = expStack.pop();
        op2 = expStack.pop();
        // LOG(INFO) << "Pushing + " << op1 + op2 << '\n';
        expStack.push(op1 + op2);
      } else if (token.find('-') != std::string::npos) {
        op1 = expStack.pop();
        op2 = expStack.pop();
        // LOG(INFO) << "Pushing - " << op1 - op2 << '\n';
        expStack.push(op2 - op1);
      } else if (token.find('x') != std::string::npos) {
        op1 = expStack.pop();
        op2 = expStack.pop();
        // LOG(INFO) << "Pushing * " << op1 * op2 << '\n';
        expStack.push(op1 * op2);
      } else if (token.find('/') != std::string::npos) {
        op1 = expStack.pop();
        op2 = expStack.pop();
        if (op1 == 0.0 || op2 == 0.0) {
          throw std::invalid_argument("Division by 0 is not possible!");
        }
        // LOG(INFO) << "Pushing / " << op1 / op2 << '\n';
        expStack.push((op2 / op1));

      }
    }
  }
  return std::to_string(expStack.pop());
}
