#include "argparse.h"
#include <stdexcept>

// scan arguements
void Argparse::run(int argc, char* argv[]) {
    // iterate arguements (ignore program name)
    for (int i=1; i < argc; i++) {
        // small name arguement discovered
        if (sizeof(argv[i]) == 2 && argv[i][0] == '-') {
            // check arguement exists
            if (isArg(argv[i][1])) {
                // get arguement matched
                Arg* a = getArg(argv[i][1]);

                // arguement found
                a->exists = 1;
                // requires an input following
                if (a->state) {
                    // set input value
                    a->value = argv[i + 1];
                    // skip ahead (past input)
                    i++;
                }
            }
        }

        // long name arguement discovered
        else if (sizeof(argv[i]) > 2 && argv[i][0] == '-' && argv[i][1] == '-') {
            // string arguement
            std::string sarg = argv[i];
            // arguement substring
            std::string sub = sarg.substr(2, sarg.size() - 1);
            // check arguement exists
            if (isArg(sub)) {
                // get arguement matched
                Arg* a = getArg(sub);

                // arguement found
                a->exists = 1;
                // requires an input following
                if (a->state) {
                    // set input value
                    a->value = argv[i + 1];
                    // skip ahead (past input)
                    i++;
                }
            }
        }

        // loose arguement
        else {
            loose.push_back(argv[i]);
        }
    }
}

// add new arguement
void Argparse::add(char s, std::string l, int st) {
    args.push_back(Arg(s, l, st));
}


// check arguement exists (given small name)
int Argparse::isArg(char name) {
    // iterate arguements
    for (Arg& a : args) {
        // name match
        if (a.small == name) {
            return 1;
        }
    }
    return 0;
}
// check arguement exists (given long name)
int Argparse::isArg(std::string name) {
    // iterate arguements
    for (Arg& a : args) {
        // name match
        if (a.big == name) {
            return 1;
        }
    }
    return 0;
}

// get arguement instance (given small name)
Arg* Argparse::getArg(char name) {
    // iterate arguements
    for (Arg& a : args) {
        // name match
        if (a.small == name) {
            return &a;
        }
    }
    throw std::invalid_argument("Arguement does not exist");
}
// get arguement instance (given long name)
Arg* Argparse::getArg(std::string name) {
    // iterate arguements
    for (Arg& a : args) {
        // name match
        if (a.big == name) {
            return &a;
        }
    }
    throw std::invalid_argument("Arguement does not exist");
}
