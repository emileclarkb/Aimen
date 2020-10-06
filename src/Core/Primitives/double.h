#ifndef DOUBLE_H
#define DOUBLE_H

class Integer;
class Float;
class String;
class Character;
class Boolean;

class Double {
    public:
        Double(double =0);
        Double(Integer);
        Double(Float);
        Double(String);
        Double(Character);
        Double(Boolean);

        double value;

        // Double Operations
        Double operator+(Double);
        Double operator+(Integer);
        Double operator+(Float);
        Double operator+(Boolean);

        Double operator-();

        Double operator-(Double);
        Double operator-(Integer);
        Double operator-(Float);
        Double operator-(Boolean);

        Double operator*(Double);
        Double operator*(Integer);
        Double operator*(Float);
        Double operator*(Boolean);

        Double operator/(Double);
        Double operator/(Integer);
        Double operator/(Float);
        Double operator/(Boolean);
};

#endif
