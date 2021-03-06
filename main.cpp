#include "Lexer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

int main (int argc, char** argv) {
    std::ifstream ifs;
    std::string input;
    std::string fileName = argv[1];
    std::stringstream s;

    Lexer* lexer = new Lexer();

    ifs.open(fileName);
    if (!ifs.is_open()) {
        std::cout << "File " << fileName << " could not open." << std::endl;
    }


    s << ifs.rdbuf();
    input = s.str();

    ifs.close();

    Lexer().toString(Lexer().Run(input));

    delete lexer;

    return 0;
}