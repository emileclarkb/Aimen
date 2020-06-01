#ifndef BASE_H
#define BASE_H

// reading to files

// file struct
typedef struct FILE_STRUCT{
    char filename[25]; // file
    int line; // current line
    char contents[]; // file contents
} file;

// init new file
file* initFile(char filename[]);

// read entire file
void readFile(file *obj);
// read next line in file
// char readline(file *obj);
#endif
