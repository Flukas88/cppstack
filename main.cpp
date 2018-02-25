#include "stack.hpp"
#include "utils.hpp"

int main(int argc, char **argv) {
  if (checkArgs(argc)) {
    Stack the_stack;
    std::vector<std::string> tokens = the_stack.split(argv[1], ' ');
    try {
      std::cout << "Res of " << argv[1] << " is "
                << parseExp(the_stack, tokens);
    } catch (const std::invalid_argument &e) {
      std::cerr << "exception: " << e.what() << std::endl;
    }
  } else {
    std::cerr << "You need to specify an exp to evaluate such as "5 10 x 2/" << std::endl;
  }
  return 0;
}
