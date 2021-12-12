#ifndef VISUAL_H
#define VISUAL_H

#include "token.h"
#include <string>
#include <vector>

// convert TokenType to string name
std::string tokenString(TokenType);

// print a token vector
void printVec(std::vector<Token>&);

// print a token tree
void printTree(std::vector<std::vector<Token>>&);

#endif
