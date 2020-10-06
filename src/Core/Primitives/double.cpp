#include "integer.h"
#include "float.h"
#include "double.h"
#include "string.h"
#include "character.h"
#include "boolean.h"
#include <sstream>

// Double Construction
Double::Double(double v) {
    value = v;
}
Double::Double(Integer v){
    value = (double) v.value;
}
Double::Double(Float v){
    value = (double) v.value;
}
Double::Double(String v){
    std::istringstream (v.value) >> value;
}
Double::Double(Character v){
    value = (double) (v.value - '0');
}
Double::Double(Boolean v){
    value = (double) v.value;
}


// Double Operations
Double Double::operator+(Double v) {
    return Double(value+v.value);
}
Double Double::operator+(Integer v) {
    return Double(value+v.value);
}
Double Double::operator+(Float v) {
    return Double(value+v.value);
}
Double Double::operator+(Boolean v) {
    return Double(value+v.value);
}

Double Double::operator-() {
    return Double(-value);
}

Double Double::operator-(Double v) {
    return Double(value-v.value);
}
Double Double::operator-(Integer v) {
    return Double(value-v.value);
}
Double Double::operator-(Float v) {
    return Double(value-v.value);
}
Double Double::operator-(Boolean v) {
    return Double(value-v.value);
}

Double Double::operator*(Double v) {
    return Double(value*v.value);
}
Double Double::operator*(Integer v) {
    return Double(value*v.value);
}
Double Double::operator*(Float v) {
    return Double(value*v.value);
}
Double Double::operator*(Boolean v) {
    return v.value ? Double(value) : Double();
}

Double Double::operator/(Double v) {
    return Double(value/v.value);
}
Double Double::operator/(Integer v) {
    return Double(value/v.value);
}
Double Double::operator/(Float v) {
    return Double(value/v.value);
}
Double Double::operator/(Boolean v) {
    return Double(value/v.value);
}
