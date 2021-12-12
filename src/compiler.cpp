#include "compiler.h"
#include "util/visualize/visual.h"

Compiler::Compiler(std::vector<std::string> fs) {
    // set given list of files
    files = fs;

    // use loose strings as files to compile
    for (std::string& f : files) {
        // tokenize file
        lexer.lex(f);
        // add tokens to tree
        tree.push_back(lexer.tokens);
        // visualize token vector
        printVec(lexer.tokens);
    }
}
