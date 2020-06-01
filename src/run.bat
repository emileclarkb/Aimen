:: program to quickly compile and run aimen.c and all dependancies

@echo off

::gcc aimen.c -o aimen
gcc aimen.c Core/base.c -o aimen -Wall -Wextra


:: gcc sets color to white
color a

:: run
aimen
:: clear
del aimen.exe
