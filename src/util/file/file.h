#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

std::string readFile(const char*);
void writeFile(const char*, std::string);

int fileSize(const char*);

std::vector<std::string>* listDir(std::string);
unsigned int dirSize(std::string);

bool isFile(std::string);

std::string fileExt(std::string&);
std::string fileName(std::string&);


#endif
