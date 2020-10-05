#ifndef LEX_H
#define LEX_H

#include "Primitives/token.h"
#include <string>
#include <vector>

class Lexer {
    public:
        // token vector
        std::vector<Token> toks;

        // lex single line
        std::vector<Token> lexLine(std::string);
        // lex entire file
        std::vector<Token> lex(std::string);

        // get lex tok corresponding to raw operator
        static std::string opCorre(std::string&);
        // get lex tok corresponding to raw single symbol
        static std::string singleSymCorre(char&);

        // push token to tokens if not empty
        void pushTok(std::string&, tokType, std::vector<Token>&);
    private:
        // currently in string
        bool inString = false;
        // currently in multi-line comment
        bool inMLComm = false;
};

#endif
