#ifndef FUNCTION_H
#define FUNCTION_H

#include <token.h>
#include <variable.h>
#include <string>
#include <vector>

struct Function {
    // function name
    std::string name;

    // return type
    tokType returnType;

    // multiple sets of parameters and vectors to support overloading
    // parameters
    std::vector<std::vector<Variable>> parameters;
    // token vectors
    std::vector<std::vector<Token>> source;
};

#endif
