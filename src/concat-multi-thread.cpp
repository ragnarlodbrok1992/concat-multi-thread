#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

typedef struct Token {
    std::string value;
    int line;
    int row;
} Token;

int main(int argc, char** argv) {
    // Interpreter variables
    std::string file_extension = "cmt";
    std::string input_file = "None";
    std::vector<std::string> options;
    std::vector<std::string> lines;
    std::vector<Token> tokens;
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
        std::string token;
        std::string line;
        char separator = ' ';
        char separator_new_line = '\n';

        // Open file
        code_file.open(input_file);

        // Parsing goes here
        // 4. Tokenize input
        data = std::string((std::istreambuf_iterator<char>(code_file)), std::istreambuf_iterator<char>());
        std::istringstream stream(data);
        int line_num = 0;
        while (std::getline(stream, line, separator_new_line)) {
            lines.push_back(line);
            std::istringstream line_stream(line);
            // Find a way to add line and row for each token
            while (std::getline(line_stream, token, separator)) {
                tokens.push_back(Token({token, line_num, 0}));
                // DEBUG
                std::cout << "Line_stream: " << line_stream.str() << std::endl;
            }
            line_num++;
        }

        // 5. Iterate tokens_strings
        int num = 0;
        for (auto tok : tokens) {
            // DEBUG
            std::cout << "Token: " << num << std::endl;
            std::cout << "Value: " << tok.value << std::endl;
            std::cout << "Line:  " << tok.line << std::endl;
            std::cout << "Row:   " << tok.row << std::endl;
            std::cout << "==========================" << std::endl;
        }

        // Close file
        code_file.close();
    }

    return 0;
}
