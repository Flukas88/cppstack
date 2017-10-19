#include "stack.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "You need to specify an exp to evaluate" << endl;
    } else {
        Stack the_stack;
        vector<string> tokens = the_stack.split(argv[1], ' ');
        try {
            cout << "Res of " << argv[1] << " is " << parseExp(the_stack, tokens);
        } catch (const std::invalid_argument &e) {
            cerr << "exception: " << e.what() << endl;
        }
    }
    return 0;
}