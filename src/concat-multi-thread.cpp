#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    // Interpreter variables
    std::string file_extension = "cmt";
    std::string input_file = "None";
    std::vector<std::string> options;
    std::vector<std::string> tokens;
    std::fstream code_file;

    // Runtime start
    std::cout << "ConcatMultiThread - CMT language proof of concept." << std::endl;

    // 1. Parsing options for interpreter
    if (argc <= 1) {
        std::cout << "No input or options provided! Exiting" << std::endl;
        return 0;
    } else {
        // Slice cmd line options
        for (int slice = 1; slice < argc; slice++) {
            options.push_back(argv[slice]);
        }
    }
    
    // 2. Validate if provided option is .cmt source file
    for (auto x : options) {
        // DEBUG
        std::cout << "Iterating parsed options: " << x << std::endl;

        if (x.ends_with(file_extension)) {
            // DEBUG
            std::cout << "Found file! " << x << std::endl;
            input_file = x;
        }
    }

    // 3. Parse .cmt file
    // DEBUG
    if (input_file.compare("None") != 0) {
        std::cout << "Input file: " << input_file << std::endl;
        std::string data;

        // Open file
        code_file.open(input_file);

        // Parsing goes here
        data = std::string((std::istreambuf_iterator<char>(code_file)), std::istreambuf_iterator<char>());
        // DEBUG
        std::cout << "Parsed data:\n" << data << std::endl;

        // Close file
        code_file.close();
    }

    return 0;
}
