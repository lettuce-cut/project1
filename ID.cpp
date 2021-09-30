#include "ID.h"
#include <iostream>
void IDAutomaton::S0(const std::string& input) {
    if (std::isalpha(input[index])) {
        while (input[index]!='\n' || input[index]!=' ') {
            inputRead++;
            index++;
        }
    }
    else {
        Serr();
    }
}