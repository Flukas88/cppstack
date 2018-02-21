//
// Created by lfrances on 21-Feb-18.
//

#include "../include/utils.h"
#include "../include/stack.h"

bool checkArgs(int argc, char **argv) { return argc < 2 ? false : true; }

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