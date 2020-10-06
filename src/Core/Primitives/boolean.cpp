#include "integer.h"
#include "float.h"
#include "double.h"
#include "string.h"
#include "character.h"
#include "boolean.h"

// Boolean Construction
Boolean::Boolean(bool v) {
    value = v;
}
Boolean::Boolean(Integer v) {
    value = (bool) v.value;
}
Boolean::Boolean(Float v) {
    value = (bool) v.value;
}
Boolean::Boolean(Double v) {
    value = (bool) v.value;
}
Boolean::Boolean(String v) {
    value = (v.value != "") ? true : false;
}
Boolean::Boolean(Character v) {
    value = (bool) v.value;
}


// Integer Operations
Integer Boolean::operator+(Boolean v) {
    return Integer(value+v.value);
}
Integer Boolean::operator+(Integer v) {
    return Integer(value+v.value);
}
Float Boolean::operator+(Float v) {
    return Float(value+v.value);
}
Double Boolean::operator+(Double v) {
    return Double(value+v.value);
}

Integer Boolean::operator-() {
    return Integer(-value);
}

Integer Boolean::operator-(Boolean v) {
    return Integer(value-v.value);
}
Integer Boolean::operator-(Integer v) {
    return Integer(value-v.value);
}
Float Boolean::operator-(Float v) {
    return Float(value-v.value);
}
Double Boolean::operator-(Double v) {
    return Double(value-v.value);
}

Integer Boolean::operator*(Boolean v) {
    return Integer(value*v.value);
}
Integer Boolean::operator*(Integer v) {
    return Integer(value*v.value);
}
Float Boolean::operator*(Float v) {
    return Float(value*v.value);
}
Double Boolean::operator*(Double v) {
    return Double(value*v.value);
}
String Boolean::operator*(String v) {
    return value ? String(v.value) : String();
}
Character Boolean::operator*(Character v) {
    return value ? Character(v.value) : Character();
}

Integer Boolean::operator/(Boolean v) {
    return Double(value/v.value);
}
Double Boolean::operator/(Integer v) {
    return Double(value/v.value);
}
Double Boolean::operator/(Float v) {
    return Double(value/v.value);
}
Double Boolean::operator/(Double v) {
    return Double(value/v.value);
}
