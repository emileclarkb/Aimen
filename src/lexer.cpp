#include "lexer.h"
#include "token.h"
#include "util/file/file.h"

#include <iostream>
#include <fstream>
#include <stdexcept>


// lex a given file
void Lexer::lex(std::string file) {
    // create file stream
    std::ifstream f(file);
    // iterate lines in file (avoid holding entire file in memory)
    std::string line;
    while (getline(f, line)) {
        // iterate characters in line
        for (char& c : line) {
            // setup indentation level at the start of the line
            if (lineStart) {
                // create new space token
                if (c == ' ') {
                    tokens.push_back(Token::space());
                }
                // create new tab token
                else if (c == '\t') {
                    tokens.push_back(Token::tab());
                }

            }

            // whitespace encountered (not at the start of the line)
            if (c == ' ' || c == '\t' || c == '\n') {
                // push token to vector
                pushCurrent();
            }

            // end current line
            else if (c == ';') {
                lineStart = 1;
                // push token to vector
                pushCurrent();
            }

            // actual character detected
            else {
                // characters type
                TokenType ctype = charType(c);

                // no longer at the start of the line
                lineStart = 0;

                // entered a new token
                if (!constructing) {
                    constructing = 1;

                    // starting character is a character (var token)
                    if (ctype == TokenType::var) {
                        current.type = TokenType::var;
                    }
                    // starting character is a symbol (sym token)
                    else if (ctype == TokenType::sym) {
                        current.type = TokenType::sym;
                    }
                    // starting character is a number (num token)
                    else if (ctype == TokenType::num) {
                        current.type = TokenType::num;
                    }
                    else {
                        throw std::invalid_argument("Bro what else is it tho? [#1]");
                    }
                }
                // continue building an old token
                else {
                    // if statement determines whether the token state has changed or
                    // the character that doesn't follow variable naming convention
                    // (possibly allows to remove the previous whitespace test)
                    if ((current.type != ctype) ||
                        ((current.type = TokenType::var) && (ctype != TokenType::num))) {
                        // push token to vector
                        pushCurrent();
                        // create new token
                        current.type = ctype;
                    }
                }
                current.value += c;
            }
        }

        // final token was never pushed
        if (constructing) {
            pushCurrent();
        }

        // push token vector to tree
        tree.push_back(tokens);
        // clear token vector
        tokens.clear();
    }
}


// get character type
TokenType Lexer::charType(char& c) {
    if (c == ' ') {
        return TokenType::space;
    }
    else if (c == '\t') {
        return TokenType::tab;
    }
    else if (isVar(c)) {
        return TokenType::var;
    }
    else if (isSym(c)) {
        return TokenType::sym;
    }
    else if (isNum(c)) {
        return TokenType::num;
    }
    else {
        throw std::invalid_argument("Bro what else is it tho? [#2]");
    }
}

// is a "variable" character
int Lexer::isVar(char& c) {
    // check character range
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || (c == '_')) {
        return 1;
    }
    return 0;
}
// is a "symbol" character
int Lexer::isSym(char& c) {
    // check character range (ignores "_" as that is a variable character)
    if (('!' <= c && c <= '/') || (':' <= c && c <= '@') ||
        ('[' <= c && c <= '^') || ('{' <= c && c <= '~') || (c == '`')) {
        return 1;
    }
    return 0;
}
// is a "numeral" character
int Lexer::isNum(char& c) {
    // check character range
    if ('0' <= c && c <= '9') {
        return 1;
    }
    return 0;
}

// push current token
void Lexer::pushCurrent() {
    // exit current token construction
    constructing = 0;
    // push new token
    tokens.push_back(current);
    // reset value
    // the type will be changed later and does not require reset
    current.value = "";
}
