#ifndef OBJECT_H
#define OBJECT_H

#include "function.h"
#include "variable.h"
#include <string>
#include <vector>

// access modifiers
enum accessModifier {
    AM_PUBLIC,
    AM_PRIVATE,
    AM_PROTECTED
};

struct Object {
    // object name
    std::string type;

    // constructor and deconstructor
    Function constructor;
    Function deconstructor;

    // object properties
    std::vector<Variable> Variables;
    std::vector<Function> Functions;
};


#endif
