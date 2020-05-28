:: program to quickly compile and run aimen.c and all dependancies

@echo off

gcc aimen.c Core/Libraries/library.c Core/lexer.c Core/parser.c -o aimen

color a
aimen
