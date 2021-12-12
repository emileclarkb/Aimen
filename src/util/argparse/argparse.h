#ifndef ARGPARSE_H
#define ARGPARSE_H

#include "arguement.h"
#include <vector>

class Argparse {
    public:
        // scan arguements
        void run(int, char*[]);
        // add new arguement (given small and big arguement aliases)
        // bool value dictates whether the arguement should be followed an input
        void add(char, std::string, int);

        // check arguement exists
        int isArg(char);
        int isArg(std::string);

        // get arguement instance
        Arg* getArg(char);
        Arg* getArg(std::string);

        // vector of "loose" strings (not associated with any arguement)
        std::vector<std::string> loose;

    private:
        // vector of arguements
        std::vector<Arg> args;
};

#endif
