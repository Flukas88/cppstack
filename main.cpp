#include "stack.h"
#include "utils.h"

using namespace std;


int main(int argc, char **argv) {
    if (checkArgs(argc, argv)) {
        Stack the_stack;
        vector<string> tokens = the_stack.split(argv[1], ' ');
        try {
            cout << "Res of " << argv[1] << " is " << parseExp(the_stack, tokens);
        } catch (const std::invalid_argument &e) {
            cerr << "exception: " << e.what() << endl;
        }
    } else {
        cerr << "You need to specify an exp to evaluate" << endl;
    }
    return 0;
}