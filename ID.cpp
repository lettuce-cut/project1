#include "ID.h"
#include <iostream>
void IDAutomaton::S0(const std::string& input) {
    if (std::isalpha(input[index])) {
        while (std::isalnum(input[index])) {
            inputRead++;
            index++;
            S0(input);
        }
    }
    else {
        Serr();
    }
}