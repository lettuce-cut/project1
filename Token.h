#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <utility>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    QMARK,
    LEFTPAREN,
    RIGHTPAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    STRING,
    ID,
    MULTICOMMENT,
    COMMENT,
    UNDEFINED,
    END
    // TODO: add the other types of tokens
};

class Token
{
private:
    // TODO: add member variables for information needed by Token

public:
    Token();
    Token(TokenType type, std::string value, int line) { this->type = type; this->value = std::move(value); this->line = line; }
//    const char *type;
    TokenType type;
    std::string value;
    int line;
    // TODO: add other needed methods
    std::string toString() const;
};

#endif // TOKEN_H

