#include "token.h"
#include <ctype.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

// determine token type
// integer.float.double
tokType detIFD(std::string &token) {
    // token string length
    int length = token.length();

    // can be simplified to an integer
    bool intConvert = true;
    // location of decimal point (-1 == no decimal point)
    int decLoc = -1;

    // integer style checking
    for (int i=0; i<length; i++) {
        // roundable to int
        if (decLoc != -1 && i > decLoc && token[i] != '0') {
            intConvert = false;
        }
        // enter decimal form
        else if (token[i] == '.') {
            //  decimal occured twice
            if (decLoc != -1) {
                throw std::invalid_argument("Decimal point cannot have multiple occurances!");
            }

            decLoc = i;
        }
        // character is not numerical
        else if (!isdigit(token[i])) {
            throw std::invalid_argument("Characters in numbers must be numerical!");
        }
    }

    // if !intConvert then decimal must == true
    // therefore decLoc can be used freely

    // converatable to int
    if (intConvert) {
        return TOK_INTEGER;
    }
    // convertable to float
    else if (length - decLoc-1 <= 7) {
        return TOK_FLOAT;
    }
    // default to double return
    else {
        return TOK_DOUBLE;
    }
}

// determine general token type
tokType detGen(std::string &token) {
    // boolean check
    if (token == "true" || token == "false") {
        return TOK_BOOLEAN;
    }
    // integer.float.double check
    // only if first char is number or dot
    else if (isdigit(token[0]) || token[0] == '.') {
        try {
            tokType type = detIFD(token);
            return type;
        }
        catch (std::invalid_argument) {}
    }

    // default to variable
    return TOK_VARIABLE;
}

// map tokType to string equivalent
std::string tokMap(tokType &type) {
    switch (type) {
        case 0:
            return "TOK_INTEGER";
        case 1:
            return "TOK_FLOAT";
        case 2:
            return "TOK_DOUBLE";
        case 3:
            return "TOK_STRING";
        case 4:
            return "TOK_CHARACTER";
        case 5:
            return "TOK_BOOLEAN";
        case 6:
            return "TOK_OPERATOR";
        case 7:
            return "TOK_VARIABLE";
        default:
            return "TOK_SYMBOL";
    }
}

// print details of token vector
void vecBrief(std::vector<Token> &tokens) {
    // token vector size
    int sz = tokens.size();
    // print token vector size
    std::cout << "Size: " << sz << std::endl << std::endl;
    // print token vector contents
    for (int i=0; i < sz * 2; i++) {
        // space between types and values
        if (i == sz) {
            std::cout << std::endl;
        }

        // token types
        if (i < sz) {
            std::cout << tokMap(tokens[i].type) << " ";
        }
        // token values
        else {
            // differ usage between tkn.value and tkn.charValue
            if (tokens[i%sz].type == TOK_CHARACTER) {
                std::cout << tokens[i%sz].charValue << ' ';
            }
            else {
                std::cout << tokens[i%sz].value << ' ';
            }
        }
    }
    // blank line
    std::cout << std::endl;
}


// primitive token arithmetic
Token tokAdd(Token &a, Token &b) {
    Token tkn;
    std::stringstream ss;

    // integer, integer addition
    if (a.type == TOK_INTEGER && b.type == TOK_INTEGER) {
        tkn.type = TOK_INTEGER;
        ss << (std::stoi(a.value) + std::stoi(b.value));
        ss >> tkn.value;
    }
    // integer, float addition
    else if (a.type == TOK_INTEGER && b.type == TOK_FLOAT) {
        tkn.type = TOK_FLOAT;
        ss << (std::stoi(a.value) + std::stof(b.value));
        ss >> tkn.value;
    }
    else if (a.type == TOK_FLOAT && b.type == TOK_INTEGER) {
        tkn.type = TOK_FLOAT;
        ss << (std::stoi(a.value) + std::stof(b.value));
        ss >> tkn.value;
    }


    return tkn;
}

/*
Token tokSub(Token&, Token&);
Token tokMul(Token&, Token&);
Token tokDiv(Token&, Token&);
Token tokMod(Token&, Token&);
Token tokEq(Token&, Token&);




Capable of Arithmetic or not:

integer       /
float         /
double        /
string        /
char          /
bool          /
operator      X
variable      X
symbol        X


Primitive Arithmetic I'll Implement
Legend:
    input1.input2 | return type

int.int       | int
int.float     | float
int.double    | double
str.str       | str
str.char      | str
*/
