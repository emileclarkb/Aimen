#ifndef VARIABLE_H
#define VARIABLE_H

#include "token.h"
#include <string>

struct Variable {
    // variable name
    std::string name;
    // variable token (includes type and value of variable)
    Token token;
};

#endif
