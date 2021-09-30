#include "MultiComment.h"

void MultiCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void MultiCommentAutomaton::S1(const std::string& input) {
    if (input[index] == EOF){
//        std::cout << "S1 Serr" << std::endl;
        Serr();
    }
    else if (input[index] == '|') {
//        std::cout << "S1 |" << std::endl;
        inputRead++;
        index++;
        S2(input);
    }
}
void MultiCommentAutomaton::S2(const std::string& input) {
    if (input[index] == EOF) {
        Serr();
    }
    else if (input[index] == '|') {
//        std::cout << "S2 |" << std::endl;
        inputRead++;
        index++;
        S3(input);
    }
    else {
//        if (input[index] == '\n'){
//            newLines++;
//        }
//        std::cout << "S2 Else" << std::endl;
        inputRead++;
        index++;
        S2(input);
    }
}

void MultiCommentAutomaton::S3(const std::string& input) {
//    std::cout << "S3 Current Index: " << input[index] << std::endl;
//    std::cout << "S3 Current Read: " << input.substr(0,index) << std::endl;
    if (input[index] == EOF) {
//        std::cout << "S3 Serr" << std::endl;
        Serr();
    }
    else if (input[index] == '#') {
//        std::cout << "S3 #" << std::endl;
        inputRead++;
        type = TokenType::COMMENT;
    }
    else if (input[index] == '\n'){
            inputRead++;
            index++;
            S2(input);
        }
    else {
//        std::cout << "S3 else" << std::endl;
        inputRead++;
        index++;
        S1(input);
        type = TokenType::UNDEFINED;
    }
}

//void MultiCommentAutomaton::S4(const std::string& input) {
//    if (input[index])
//}





//Below is for the combined comment automaton that was working the best
//void CommentAutomaton::S0(const std::string& input) {

//    if (input[index] == '#') {
//        inputRead++;
//        index++;
//        S1(input);
//    }
//    else {
//        Serr();
//    }
//}
//
//void CommentAutomaton::S1(const std::string& input) {
//    if (input[index] == '|') {
//        inputRead++;
//        index++;
//        S2(input);
//    }
//    else if (input[index] == '\n'){
//        inputRead++;
//    }
//    else {
//        inputRead++;
//        index++;
//        S1(input);
//
//    }
//}
//void CommentAutomaton::S2(const std::string& input) {
//    if (input[index] == '|') {
//        inputRead++;
//        index++;
//        S3(input);
//    }
//    else {
//        S2(input);
//    }
//}
//void CommentAutomaton::S3(const std::string& input) {
//    if (input[index] == '#') {
//        inputRead++;
//        index++;
//        S4(input);
//    }
//    else {
//        S2(input);
//    }
//}
//void CommentAutomaton::S4(const std::string& input) {
//    if (input[index] == '\n') {
//        inputRead++;
//    }
//    else {
//        S2(input);
//    }
//}


