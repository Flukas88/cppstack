#include <stack.hpp>
#include <utils.hpp>


auto main(int argc, char **argv) -> int {
  if (checkArgs(argc)) {
    Stack theStack;
    std::vector<std::string> tokens = tokenize(argv[1], ' ');
    try {
      std::cout << "Res of " << argv[1] << " is " << parseExp(theStack, tokens)
                << "\n";
    } catch (const std::invalid_argument &e) {
      std::cerr << "exception: " << e.what() << '\n';
    }
  } else {
    std::cerr << "You need to specify an exp to evaluate such as '5 10 x 2 /'";
    std::cerr << '\n';
  }
  return 0;
}
