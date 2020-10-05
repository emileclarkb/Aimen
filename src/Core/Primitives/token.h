#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>

// all possible token states
enum tokType {
    TOK_INTEGER,
    TOK_FLOAT,
    TOK_DOUBLE,
    TOK_STRING,
    TOK_CHARACTER,
    TOK_BOOLEAN,
    TOK_OPERATOR,
    TOK_VARIABLE,
    TOK_SYMBOL
};

// token structure
struct Token {
    tokType type;
    std::string value;
    char charValue;
};

// determine token type
// integer.float.double
tokType detIFD(std::string&);
// clarify general token
// integer.float.double.boolean.variable
tokType detGen(std::string&);

// map tokType to string equivalent
std::string tokMap(tokType&);

// print details of token vector
void vecBrief(std::vector<Token>&);


#endif
