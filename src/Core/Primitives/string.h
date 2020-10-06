#ifndef STRING_H
#define STRING_H

class Integer;
class Float;
class Double;
class Character;
class Boolean;

#include <string>

class String {
    public:
        String(std::string ="");
        String(Integer);
        String(Float);
        String(Double);
        String(Character);
        String(Boolean);

        std::string value;

        // Amount of characters in string
        int length();

        // String Operations
        String operator+(String);
        String operator+(Character);

        String operator*(Integer);
        String operator*(Boolean);
};

#endif
