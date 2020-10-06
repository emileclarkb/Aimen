#include "lex.h"
#include "Primitives/Base/token.h"
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>

// lex single line
std::vector<Token> Lexer::lexLine(std::string data) {
    // current tok
    std::string tok = "";
    // current special character token
    std::string special = "";
    // contents of string
    std::string strContents = "";

    // currently in string
    bool inString = false;

    // iterate characters in line
    for (int i=0; data[i] != '\0'; i++) {
        // string handling
        if (inString && data[i] != '\"') {
            strContents += data[i];
            continue;
        }
        // start/end string
        else if (data[i] == '\"') {
            // push string token
            if (inString) {
                Token tkn;
                tkn.type = TOK_STRING;
                tkn.value = strContents;
                toks.push_back(tkn);
            }

            // invert inString value
            inString = !inString;
            continue;
        }

        // space character
        else if (data[i] == ' ') {
            // add stored token
            pushTok(tok, detGen(tok), toks);
            // add stored special
            if (special != "") {
                // ignore rest of line if in comment
                if (special == "//") {
                    break;
                }
                // start multi-line comment
                else if (special == "/*") {
                    inMLComm = true;
                    // reset special
                    special = "";
                    continue;
                }
                // end multi-line comment
                else if (special == "*/") {
                    inMLComm = false;
                    // reset special
                    special = "";
                    continue;
                }

                // temp token
                Token tkn;
                tkn.type = TOK_OPERATOR;
                tkn.value = opCorre(special);

                // push if not commented
                if (!inMLComm) {
                    toks.push_back(tkn);
                }
                special = "";
            }
            continue;
        }
        // character handling
        else if (data[i] == '\'') {
            // initialize character token
            Token tkn;
            tkn.type = TOK_CHARACTER;

            // find location of character end
            if (data[i+1] == '\'') {
                tkn.charValue = '\0';
                i++; // skip ahead
            }
            else if (data[i+2] == '\'' && data[i+1] != '\\') {
                tkn.charValue = (char)data[i+1];
                i+=2; // skip ahead
            }
            else if (data[i+3] == '\'' && data[i+1] == '\\') {
                tkn.charValue = (char)(data[i+1]+data[i+2]);
                i += 3; // skip ahead
            }
            else {
                throw std::invalid_argument("Invalid size bound to char!");
            }

            // push
            toks.push_back(tkn);
            continue;
        }

        // single special characters
        else if (data[i] == '(' || data[i] == ')' || data[i] == '[' ||
                 data[i] == ']' || data[i] == '{' || data[i] == '}' ||
                 data[i] == ';' || data[i] == ':' || data[i] == ',') {
            // push if not commented
            if (!inMLComm) {
                // push any tokens
                pushTok(tok, detGen(tok), toks);

                // temp token
                Token tkn;
                // if special characters exist
                if (special != "") {
                    // push  special characters
                    tkn.type = TOK_OPERATOR;
                    tkn.value = opCorre(special);
                    toks.push_back(tkn);
                    // empty
                    special = "";
                }

                // push symbol
                tkn.type = TOK_SYMBOL;
                tkn.value = singleSymCorre(data[i]);
                toks.push_back(tkn);
            }
            continue;
        }
        // other special characters
        if (data[i] == '=' || data[i] == '+' || data[i] == '-' ||
            data[i] == '*' || data[i] == '/' || data[i] == '%' ||
            data[i] == '!' || data[i] == '>' || data[i] == '<' ||
            data[i] == '|' || data[i] == '&' || data[i] == '.') {
            // push token
            pushTok(tok, detGen(tok), toks);

            // add char to special
            special += data[i];
            continue;
        }
        // reached end of special character/s
        if (special != "") {
            // ignore rest of line if in comment
            if (special == "//") {
                break;
            }
            // start multi-line comment
            else if (special == "/*") {
                inMLComm = true;
                // reset special
                special = "";
                continue;
            }
            // end multi-line comment
            else if (special == "*/") {
                inMLComm = false;
                // reset special
                special = "";
                continue;
            }

            // temp token
            Token tkn;
            tkn.type = TOK_OPERATOR;
            tkn.value = opCorre(special);
            // push if not commented
            if (!inMLComm) {
                toks.push_back(tkn);
            }

            // reset special
            special = "";
        }

        // section not commented
        if (!inMLComm) {
            tok += data[i];
        }
    }

    // push anything left after null character reached
    // push remaining tok
    pushTok(tok, detGen(tok), toks);
    // push remaining special characters
    if (special != "") {
        // pointless comment
        if (special == "//") {}
        // start multi-line comment
        else if (special == "/*") {
            inMLComm = true;
        }
        // end multi-line comment
        else if (special == "*/") {
            inMLComm = false;
        }
        else {
            Token tkn;
            tkn.type = TOK_OPERATOR;
            tkn.value = opCorre(special);
            toks.push_back(tkn);
        }
    }

    return toks;
}

// lex entire file
std::vector<Token> Lexer::lex(std::string fName) {
    // open input stream
    std::ifstream file(fName);

    // iterate lines in file
    std::string str;
    while (std::getline(file, str)) {
        lexLine(str);
    }

    return toks;
}


// get lex tok corresponding to raw operator
std::string Lexer::opCorre(std::string &op) {
    // empty string given
    if (op == "") {
        return op;
    }
    // complex operators
    else if (op == "=") {
        return "EQ";
    }
    else if (op == "+") {
        return "ADD";
    }
    else if (op == "-") {
        return "SUB";
    }
    else if (op == "*") {
        return "MUL";
    }
    else if (op == "/") {
        return "DIV";
    }
    else if (op == "%") {
        return "MOD";
    }
    else if (op == "+=") {
        return "ADDEQ";
    }
    else if (op == "-=") {
        return "SUBEQ";
    }
    else if (op == "*=") {
        return "MULEQ";
    }
    else if (op == "/=") {
        return "DIVEQ";
    }
    else if (op == "%=") {
        return "MODEQ";
    }
    else if (op == "**") {
        return "POW";
    }
    else if (op == "++") {
        return "INC";
    }
    else if (op == "--") {
        return "DEC";
    }
    else if (op == "!") {
        return "NOT";
    }
    else if (op == "!=") {
        return "NOTEQ";
    }
    else if (op == "||") {
        return "OR";
    }
    else if (op == ">") {
        return "GT";
    }
    else if (op == "<") {
        return "LT";
    }
    else if (op == ">=") {
        return "GTEQ";
    }
    else if (op == "<=") {
        return "LTEQ";
    }
    else if (op == "&&") {
        return "AND";
    }
    else if (op == ".") {
        return "DOT";
    }
    else{
        // improve error handling
        throw std::invalid_argument("Incorrect use of special characters!");
    }
}

// get lex tok corresponding to raw single symbol
std::string Lexer::singleSymCorre(char &sym) {
    // single symbols
    if (sym == '(') {
        return "LBRAC";
    }
    else if (sym == ')') {
        return "RBRAC";
    }
    else if (sym == '[') {
        return "LSQ";
    }
    else if (sym == ']') {
        return "RSQ";
    }
    else if (sym == '{') {
        return "LCURL";
    }
    else if (sym == '}') {
        return "RCURL";
    }
    else if (sym == ';') {
        return "SEMI";
    }
    else if (sym == ':') {
        return "COL";
    }
    else if (sym == ',') {
        return "COMM";
    }
    else{
        // improve error handling
        throw std::invalid_argument("Incorrect use of single symbols!");
    }
}

// push non-empty token to tokens
void Lexer::pushTok(std::string &t, tokType tType, std::vector<Token> &ts) {
    // check if empty
    if (t != "" && !inMLComm) {
        // temp token
        Token tkn;
        tkn.type = tType;
        tkn.value = t;

        // push token
        ts.push_back(tkn);
        // empty
        t = "";
    }
}
