#include "RulesAutomaton.h"

void RulesAutomaton::S0(const std::string& input) {
    if (input[index] == 'R') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S1(const std::string& input) {
    if (input[index] == 'U' || input[index] == 'u') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S2(const std::string& input) {
    if (input[index] == 'L' || input[index] == 'l') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S3(const std::string& input) {
    if (input[index] == 'E' || input[index] == 'e') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S4(const std::string& input) {
    if (input[index] == 'S' || input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}