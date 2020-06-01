#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Core/Include/base.h"
//#include "Core/Include/lexer.h"



void usage()
{

}




int main(int argc, char *argv[]){
    file *obj2 = initFile("test.txt");
    puts(obj2->filename);
}
