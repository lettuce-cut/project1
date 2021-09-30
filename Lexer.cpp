#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QmarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "StringAutomaton.h"
#include "ID.h"
#include "CommentAutomaton.h"
#include "MultiComment.h"
#include "UndefinedAutomaton.h"
#include "EOFAutomaton.h"
#include <iostream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QmarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new MultiCommentAutomaton());
    automata.push_back(new CommentAutomaton());
//    automata.push_back(new UndefinedAutomaton());

    // TODO: Add the other needed automata here
}

std::vector<Token*> Lexer::Run(std::string& input) {
    int lineNumber = 1;
    int maxRead;
    Automaton *maxAutomata;
    int inputRead;
    Token *newToken;
    int maxLines = 0;

    while (!input.empty()) {
        maxRead = 0;
        maxAutomata = automata[0];
        if (std::isspace(input[0])) {
            maxRead = 1;
            if (input[0] == '\n') {
                lineNumber++;
            }
        }
        else {
            for (long unsigned int i = 0; i < automata.size(); i++) {
                inputRead = automata[i]->Start(input);

                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomata = automata[i];
                    maxLines = maxAutomata->NewLinesRead();
                }
            }
            if (maxRead > 0) {
                newToken = maxAutomata->CreateToken(input.substr(0,maxRead), lineNumber);
                tokens.push_back(newToken);
                lineNumber += maxLines;
            }

            else {
                maxRead = 1;
                tokens.push_back(new Token(TokenType::UNDEFINED, input.substr(0, 1), lineNumber));
            }
            for (int i = 0; i < maxRead; i++) {
                if (input[i] == '\n') {
                    lineNumber++;
                }
            }
        }
        input.erase(0, maxRead);
    }
    tokens.push_back(new Token(TokenType::END, "", lineNumber));
    return tokens;
}


void Lexer::toString(std::vector<Token*> tokens) {
    if (tokens.empty()) {
        std::cout << "No tokens pushed back" << std::endl;
    }
    else {
        for (long unsigned int i = 0; i < tokens.size(); i++) {
            std::cout << tokens[i]->toString() << std::endl;
        }
    }
    std::cout << "Total Tokens = " << tokens.size() << std::endl;
}