#include "stack.h"

int main(int arc, char **argv) {
    Stack the_stack;
    vector<string> tokens = the_stack.split(argv[1], ' ');
    try {
        cout << "Res of " << argv[1] << " is " << parseExp(the_stack, tokens);
    } catch (const std::invalid_argument& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
    return 0;
}