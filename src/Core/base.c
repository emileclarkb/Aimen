#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Include/base.h"


// init new file
file* initFile(char filename[]){
    file *f = calloc(1, sizeof(struct FILE_STRUCT));
    strcpy(f->filename, filename);
    strcpy(f->contents, "");
    f->line = 0;

    return f;
}

// read file content
void readFile(file *obj){
    // open file
    exit(0);
    FILE *fptr = fopen(obj->filename, "r");

    char c; // current character
    char contents[] = ""; // file contents
    // read file
    while (c != EOF)
    {
        c = fgetc(fptr);
        strcpy(contents, &c);
    }
    fclose(fptr);
    strcpy(obj->contents, contents);
}

/*
// read next line in file
char readline(file *obj){
    char c; // current character
    char line[]; // current line content

    int pos; // current char pos
    int i; // current line position

    while (c != EOF){
        c = obj->contents[i]

        // not new line
        if (c != '\n'){
            // add character to line
            strcpy(line, c);
            pos++; // next char
        }
        // new line
        else {
            // further than previously gone
            if (i == obj->line+1){
                return line;
            }
            // repeat for next line
            else {
                // reset line
                line = "";
            }
        }
    }
}
*/
