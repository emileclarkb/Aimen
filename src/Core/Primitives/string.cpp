#include "integer.h"
#include "float.h"
#include "double.h"
#include "string.h"
#include "character.h"
#include "boolean.h"
#include <string>
#include <sstream>

// String Construction
String::String(std::string v) {
    value = v;
}
String::String(Integer v) {
    std::stringstream ss;
    ss << v.value;
    ss >> value;
}
String::String(Float v) {
    std::stringstream ss;
    ss << v.value;
    ss >> value;
}
String::String(Double v) {
    std::stringstream ss;
    ss << v.value;
    ss >> value;
}
String::String(Character v) {
    std::stringstream ss;
    ss << v.value;
    ss >> value;
}
String::String(Boolean v) {
    value = v.value ? "true" : "false";
}


// Amount of characters in string
int String::length() {
    int i;
    for (i=0; value[i] != '\0'; i++) {}
    i++;

    return i;
}


// String Operations
String String::operator+(String v) {
    return String(value+v.value);
}
String String::operator+(Character v) {
    return String(value+v.value);
}
String String::operator*(Integer v) {
    std::string temp = "";

    for (int i=0; i<v.value; i++) {
        temp+=value;
    }

    return String(temp);
}
String String::operator*(Boolean v) {
    return v.value ? String(value) : String();
}
