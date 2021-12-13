#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include <vector>
#include <string>


class Parser {
    public:
        // parse a given token vector
        void parseVec(std::vector<Token>);
        // parse a given token tree
        void parseTree(std::vector<std::vector<Token>>);
    private:

}

#endif
