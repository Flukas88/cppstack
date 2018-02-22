#ifndef CPPSTACK_UTILS_H
#define CPPSTACK_UTILS_H

#include <string>
#include "../include/stack.h"

bool checkArgs(int argc, char **argv);
std::string parseExp(Stack exp_stack, std::vector<std::string> tokens);


#endif // CPPSTACK_UTILS_H
