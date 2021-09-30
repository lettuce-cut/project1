#include "ID.h"
#include <iostream>
void IDAutomaton::S0(const std::string& input) {
    if (std::isalpha(input[index])) {
        while (index < input.size()) {
            inputRead++;
            index++;
        }
    }
    else {
        Serr();
    }
}