#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    var,
    sym,
    num,
    tab,
    space
};

class Token {
    public:
        // token type and value
        TokenType type;
        std::string value;

        // automatically construct token given type
        static Token var();
        static Token sym();
        static Token num();
        static Token tab();
        static Token space();
};

#endif
