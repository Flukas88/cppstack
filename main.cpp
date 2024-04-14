#include <stack.hpp>
#include <utils.hpp>
#include <argparse/argparse.hpp>
#include <glog/logging.h>


auto main(int argc, char **argv) -> int {
  argparse::ArgumentParser program("cppstack", "0.1.1");
  google::InitGoogleLogging(argv[0]);

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
    const std::vector<std::string> tokens = tokenize(input, ' ');

    try {
      const Stack theStack;
      auto res = parseExp(theStack, tokens);
      if (res == "nan") {
        LOG(ERROR) << "Division by 0 is not allowed\n";
        return 1;
      }
      std::cout << "Res of " << input << " is " << res
                << "\n";
    } catch (const std::invalid_argument &e) {
      LOG(ERROR) << "exception: " << e.what() << '\n';
    }
  }
  catch (const std::exception& err) {
          LOG(ERROR) << err.what() << '\n' << program << '\n';
          return 1;
  }

  return 0;
}
