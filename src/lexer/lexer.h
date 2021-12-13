#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>
#include <vector>
#include <stdbool.h>

class Lexer {
    public:
        // lex a given file
        void lex(std::string);

        // get character type
        TokenType charType(char&);

        // check character state
        int isVar(char&);
        int isSym(char&);
        int isNum(char&);

        // very plain token tree
        std::vector<std::vector<Token>> tree;
    private:
        // token vector
        std::vector<Token> tokens;

        // current token
        Token current;
        // push current token to token vector
        void pushCurrent();

        // State Variables

        // currently at the start of a line
        int lineStart = 1;
        // constructing a token?
        int constructing = 0;
};

#endif
