#include "ID.h"
#include <iostream>
void IDAutomaton::S0(const std::string& input) {
    if (std::isalpha(input[index])) {
        if (std::isspace(input[index]) == false) {
            inputRead++;
            index++;
        }
    }
    else {
        Serr();
    }
}