#ifndef CHARACTER_H
#define CHARACTER_H

class Integer;
class Float;
class Double;
class String;
class Boolean;

class Character {
    public:
        Character(char ='\0');
        Character(Integer);
        Character(Float);
        Character(Double);
        Character(String);
        Character(Boolean);

        char value;

        // Character Operations
        String operator+(Character);
        String operator+(String);

        String operator*(Integer);
        Character operator*(Boolean);
};

#endif
