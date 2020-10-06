#include "Core/lex.h"
#include "Core/Primitives/Base/token.h"
#include <string>
#include <vector>
#include <stdexcept>

int main(int argc, char *argv[]) {
    // initialize lexer
    Lexer l = Lexer();

    // token vector
    std::vector<Token> tokens;

    // load from file
    if ((std::string)argv[1] == "-f" || (std::string)argv[1] == "--file") {
        // lex file
        tokens = l.lex(argv[argc-1]);
    }
    else if ((std::string)argv[1] == "-d" || (std::string)argv[1] == "--direct") {
        // lex input
        tokens = l.lexLine(argv[argc-1]);
    }
    else {
        throw std::invalid_argument("Incorrect parameter usage!");
    }

    // print token vector details
    vecBrief(tokens);

    return 0;
}
