#include "compiler.h"
#include "util/argparse/argparse.h"

int main(int argc, char* argv[]) {
    // instantiate arguement parser
    Argparse A;
    // give command line arguements
    A.run(argc, argv);

    // instantiate compiler
    Compiler C(A.loose);

}
