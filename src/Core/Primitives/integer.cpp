#include "integer.h"
#include "float.h"
#include "double.h"
#include "string.h"
#include "character.h"
#include "boolean.h"
#include <sstream>
#include <string>

// Integer Construction
Integer::Integer(int v) {
    value = v;
}
Integer::Integer(Float v) {
    value = (int) (v.value + 0.5);
}
Integer::Integer(Double v) {
    value = (int) (v.value + 0.5 - (v.value<0));
}
Integer::Integer(String v) {
    std::istringstream (v.value) >> value;
}
Integer::Integer(Character v) {
    value = v.value - '0';
}
Integer::Integer(Boolean v) {
    value = (int) v.value;
}


// Integer Operations
Integer Integer::operator+(Integer v) {
    return Integer(value+v.value);
}
Float Integer::operator+(Float v) {
    return Float(value+v.value);
}
Double Integer::operator+(Double v) {
    return Double(value+v.value);
}
Integer Integer::operator+(Boolean v) {
    return Integer(value+v.value);
}

Integer Integer::operator-() {
    return Integer(-value);
}

Integer Integer::operator-(Integer v) {
    return Integer(value-v.value);
}
Float Integer::operator-(Float v) {
    return Float(value-v.value);
}
Double Integer::operator-(Double v) {
    return Double(value-v.value);
}
Integer Integer::operator-(Boolean v) {
    return Integer(value-v.value);
}

Integer Integer::operator*(Integer v) {
    return Integer(value*v.value);
}
Float Integer::operator*(Float v) {
    return Float(value*v.value);
}
Double Integer::operator*(Double v) {
    return Double(value*v.value);
}
String Integer::operator*(String v) {
    // temp value
    std::string temp = "";

    for (int i=0; i<value; i++) {
        temp+=v.value;
    }

    return String(temp);
}
String Integer::operator*(Character v) {
    // temp value
    std::string temp = "";

    for (int i=0; i<value; i++) {
        temp+=v.value;
    }

    return String(temp);
}
Integer Integer::operator*(Boolean v) {
    return v.value ? Integer(value) : Integer();
}

Double Integer::operator/(Integer v) {
    return Double(value/v.value);
}
Double Integer::operator/(Float v) {
    return Double(value/v.value);
}
Double Integer::operator/(Double v) {
    return Double(value/v.value);
}
Integer Integer::operator/(Boolean v) {
    return Integer(value/v.value);
}
