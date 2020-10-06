#ifndef BOOLEAN_H
#define BOOLEAN_H

class Integer;
class Float;
class Double;
class String;
class Character;

class Boolean {
    public:
        Boolean(bool =false);
        Boolean(Integer);
        Boolean(Float);
        Boolean(Double);
        Boolean(String);
        Boolean(Character);

        bool value;

        // Boolean Operations
        Integer operator+(Boolean);
        Integer operator+(Integer);
        Float operator+(Float);
        Double operator+(Double);

        Integer operator-();

        Integer operator-(Boolean);
        Integer operator-(Integer);
        Float operator-(Float);
        Double operator-(Double);

        Integer operator*(Boolean);
        Integer operator*(Integer);
        Float operator*(Float);
        Double operator*(Double);
        String operator*(String);
        Character operator*(Character);

        Integer operator/(Boolean);
        Double operator/(Integer);
        Double operator/(Float);
        Double operator/(Double);
};

#endif
