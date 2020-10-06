#include "integer.h"
#include "float.h"
#include "double.h"
#include "string.h"
#include "character.h"
#include "boolean.h"
#include <sstream>

// Float Construction
Float::Float(float v) {
    value = v;
}
Float::Float(Integer v){
    value = (float) v.value;
}
Float::Float(Double v){
    value = (float) v.value;
}
Float::Float(String v){
    std::istringstream (v.value) >> value;
}
Float::Float(Character v){
    value = (float) (v.value - '0');
}
Float::Float(Boolean v){
    value = (float) v.value;
}


// Float Operations
Float Float::operator+(Float v) {
    return Float(value+v.value);
}
Float Float::operator+(Integer v) {
    return Float(value+v.value);
}
Double Float::operator+(Double v) {
    return Double(value+v.value);
}
Float Float::operator+(Boolean v) {
    return Float(value+v.value);
}

Float Float::operator-() {
    return Float(-value);
}

Float Float::operator-(Float v) {
    return Float(value-v.value);
}
Float Float::operator-(Integer v) {
    return Float(value-v.value);
}
Double Float::operator-(Double v) {
    return Double(value-v.value);
}
Float Float::operator-(Boolean v) {
    return Float(value-v.value);
}

Float Float::operator*(Float v) {
    return Float(value*v.value);
}
Float Float::operator*(Integer v) {
    return Float(value*v.value);
}
Double Float::operator*(Double v) {
    return Double(value*v.value);
}
Float Float::operator*(Boolean v) {
    return v.value ? Float(value) : Float();
}

Double Float::operator/(Float v) {
    return Double(value/v.value);
}
Double Float::operator/(Integer v) {
    return Double(value/v.value);
}
Double Float::operator/(Double v) {
    return Double(value/v.value);
}
Float Float::operator/(Boolean v) {
    return Float(value/v.value);
}
