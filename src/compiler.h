#ifndef COMPILER_H
#define COMPILER_H

#include "lexer.h"
#include "token.h"

class Compiler {
    public:
        // compile from a list of file names
        Compiler(std::vector<std::string>);

    private:
        // lexer instance
        Lexer lexer;

        // very plain token tree
        std::vector<std::vector<Token>> tree;

        // list of files to compile
        std::vector<std::string> files;
};

#endif
