#ifndef FLOAT_H
#define FLOAT_H

class Integer;
class Double;
class String;
class Character;
class Boolean;

class Float {
    public:
        Float(float =0);
        Float(Integer);
        Float(Double);
        Float(String);
        Float(Character);
        Float(Boolean);

        int value;

        // Float Operations
        Float operator+(Float);
        Float operator+(Integer);
        Double operator+(Double);
        Float operator+(Boolean);

        Float operator-();

        Float operator-(Float);
        Float operator-(Integer);
        Double operator-(Double);
        Float operator-(Boolean);

        Float operator*(Float);
        Float operator*(Integer);
        Double operator*(Double);
        Float operator*(Boolean);

        Double operator/(Float);
        Double operator/(Integer);
        Double operator/(Double);
        Float operator/(Boolean);
};

#endif
