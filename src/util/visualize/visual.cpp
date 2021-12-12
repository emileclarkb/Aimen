#include "util/visualize/visual.h"
#include <iostream>

// convert TokenType to string name
std::string tokenString(TokenType type) {
    switch (type) {
        case TokenType::var:
            return "var";
        case TokenType::sym:
            return "sym";
        case TokenType::num:
            return "num";
        case TokenType::tab:
            return "tab";
        default:
            return "spc";
    }
}

// print a token vector
void printVec(std::vector<Token>& vector) {
    // start
    std::cout << "# ";
    // iterate tokens
    for (Token t : vector) {
        std::cout << "(" << tokenString(t.type) << ": \""<< t.value << "\") ";
    }
    // end
    std::cout << std::endl;
}

// print a token tree
void printTree(std::vector<std::vector<Token>>& tree) {
    // iterate vectors
    for (std::vector<Token> vector : tree) {
        printVec(vector);
    }
}
