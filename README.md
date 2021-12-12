# Aimen

![Aimen Logo](/design/pink.PNG)

## Description
Aimen is a language I've intended on building for a couple years now. Originally Aimen had a python interpreter ([AimenPy](https://www.github.com/emileclarkb/AimenPy)), naturally this was pretty slow. The new implementation utilizes a compilation process written predominantly in C++.

Aimen is intended to compile directly to the x86-64 instruction set and be stored as either a 64-bit Portable Executable (PE32+) EXE file or as a ELF executable (Windows and Unix respectively).

## Program Execution
The entire program execution process was written, as such Aimen has no dependencies (apart from the standard library obviously). I don't like the current and excessive uses of tools like flex and bison, hence Aimen controls everything.

Instead of following the standard design philosophy Aimen combines the compiler, assembler, and linker into a single compilation phase (which will be referenced as the compiler).
