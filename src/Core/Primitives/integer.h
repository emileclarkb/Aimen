#ifndef INTEGER_H
#define INTEGER_H

class Float;
class Double;
class String;
class Character;
class Boolean;

class Integer {
    public:
        Integer(int =0);
        Integer(Float);
        Integer(Double);
        Integer(String);
        Integer(Character);
        Integer(Boolean);

        int value;

        // Integer Operations
        Integer operator+(Integer);
        Float operator+(Float);
        Double operator+(Double);
        Integer operator+(Boolean);

        Integer operator-();

        Integer operator-(Integer);
        Float operator-(Float);
        Double operator-(Double);
        Integer operator-(Boolean);

        Integer operator*(Integer);
        Float operator*(Float);
        Double operator*(Double);
        String operator*(String);
        String operator*(Character);
        Integer operator*(Boolean);

        Double operator/(Integer);
        Double operator/(Float);
        Double operator/(Double);
        Integer operator/(Boolean);
};

#endif
