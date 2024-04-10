#include <stack.hpp>
#include <utils.hpp>
#include <argparse/argparse.hpp>


auto main(int argc, char **argv) -> int {
  argparse::ArgumentParser program("cppstack", "0.1.1");

  program.add_argument("-e", "--expression")
    .default_value(std::string("0"))
    .required()
    .help("specify the expression to parse.");

  try {
    program.parse_args(argc, argv);
  }
  catch (const std::exception& err) {
    std::cerr << err.what() << '\n';
    std::cerr << program;
    return 1;
  }

  try {
    auto input = program.get<std::string>("expression");
    Stack theStack;
    std::vector<std::string> tokens = tokenize(input, ' ');
    try {
      std::cout << "Res of " << input << " is " << parseExp(theStack, tokens)
                << "\n";
    } catch (const std::invalid_argument &e) {
      std::cerr << "exception: " << e.what() << '\n';
    }
  }
  catch (const std::exception& err) {
          std::cerr << err.what() << '\n';
          std::cerr << program;
          return 1;
  }

  return 0;
}
