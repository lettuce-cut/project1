#include "QueriesAutomaton.h"

void QueriesAutomaton::S0(const std::string& input) {
//    std::cout << "In Q SO" << std::endl;
    if (input[index] == 'Q') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S1(const std::string& input) {
//    std::cout << "In Q S1" << std::endl;
//    std::cout <<"this is S1 index: " << index << std::endl;
//    std::cout <<"This is s1 input: " << input << std::endl;
    if (input[index] == 'U' || input[index] == 'u') {
        inputRead++;
        index++;
        S2(input);
//        std::cout << "This is S1 input read" << inputRead << std::endl;
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S2(const std::string& input) {
//    std::cout << "In Q S3" << std::endl;
    if (input[index] == 'E' || input[index] == 'e') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S3(const std::string& input) {
//    std::cout << "In Q S3" << std::endl;
    if (input[index] == 'R' || input[index] == 'r') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S4(const std::string& input) {
//    std::cout << "In Q S4" << std::endl;
    if (input[index] == 'I' || input[index] == 'i') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S5(const std::string& input) {
//    std::cout << "In Q S5" << std::endl;
    if (input[index] == 'E' || input[index] == 'e') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}

void QueriesAutomaton::S6(const std::string& input) {
//    std::cout << "In Q S6" << std::endl;
    if (input[index] == 'S' || input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}