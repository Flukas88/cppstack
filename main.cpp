#include "stack.h"

int main(int arc, char **argv) {
    Stack thestack;
    vector<string> tokens = thestack.split(argv[1], ' ');
    parseExp(thestack, tokens);
    return 0;
}