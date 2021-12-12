#include "token.h"

// create a variable token
Token Token::var() {
    Token t;
    t.type = TokenType::var;
    t.value = "";
    return t;
}
// create a symbol token
Token Token::sym() {
    Token t;
    t.type = TokenType::sym;
    t.value = "";
    return t;
}
// create a numeral token
Token Token::num() {
    Token t;
    t.type = TokenType::num;
    t.value = "";
    return t;
}
// create a tab token
Token Token::tab() {
    Token t;
    t.type = TokenType::tab;
    t.value = "\t";
    return t;
}
// create a space token
Token Token::space() {
    Token t;
    t.type = TokenType::space;
    t.value = " ";
    return t;
}
