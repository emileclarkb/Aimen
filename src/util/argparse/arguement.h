#ifndef ARGUEMENT_H
#define ARGUEMENT_H

#include <string>
#include <stdbool.h>

class Arg {
    public:
        // construct arguement (prior to running)
        Arg(char, std::string, int);
        // set "exists" and "value" (arguement discovered during runtime)
        // void set(std::string v);


        // short ("small") name
        char small;
        // long ("big") name
        std::string big;
        // input state (0: doesn't require input, 1: requires input)
        int state = 0;

        // arguement has occured
        int exists = 0;
        // arguement input value;
        std::string value = "";
};

#endif
