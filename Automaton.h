#ifndef AUTOMATON_H
#define AUTOMATON_H
#include "Token.h"
#include <iostream>
#include <utility>

class Automaton
{
protected:
    int inputRead;
    int newLines;
    long unsigned int index;
    TokenType type;

public:
    // Default constructor -- since we have a constructor that takes a parameter,
    //   the compiler will autogenerate a default constructor if not explicit.
    Automaton() : Automaton(TokenType::UNDEFINED) {}

    Automaton(TokenType type) { this->type = type;}

    // Start the automaton and return the number of characters read
    //   read == 0 indicates the input was rejected
    //   read  > 0 indicates the input was accepted
    int Start(const std::string& input) {
//        std::cout << "In start " << input[0] << " " << input[1] << std::endl;
        newLines = 0;
        inputRead = 0;
        index = 0;
        if (input[0] == '\n') {
            newLines++;
        }
        S0(input);
//        std::cout << "This is InputRead" << inputRead << std::endl;
//        std::cout <<"Start index is " << index << std::endl;
        return inputRead;
    }

    // Every subclass must define this method
    virtual void S0(const std::string& input) = 0;

    void Serr() {
        // Indicate the input was rejected
        inputRead = 0;
    }

    virtual Token* CreateToken(std::basic_string<char> input, int lineNumber) {
        return new Token(type, input, lineNumber);
    }

    int NewLinesRead() const { return newLines; }
};

#endif // AUTOMATON_H

