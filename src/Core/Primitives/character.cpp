#include "integer.h"
#include "float.h"
#include "double.h"
#include "string.h"
#include "character.h"
#include "boolean.h"
#include <stdexcept>

// Character Construction
Character::Character(char v) {
    value = v;
}
Character::Character(Integer v) {
    // temp
    String vt = String(v);

    if (vt.length() == 1) {
        value = Character(v).value;
    }
    else {
        throw std::invalid_argument("Integer length does not match single character!");
    }
}
Character::Character(Float v) {
    value = Character(Integer(v)).value;
}
Character::Character(Double v) {
    value = Character(Integer(v)).value;
}
Character::Character(String v) {
    if (v.length() == 1) {
        value = v.value[0];
    }
    else {
        throw std::invalid_argument("String length does not match single character!");
    }
}
Character::Character(Boolean v) {
    value = v.value ? '1': '0';
}


// Character Operations
String Character::operator+(Character v) {
    std::string temp = ""+value;
    temp += v.value;
    return String(temp);
}
String Character::operator+(String v) {
    return String(value+v.value);
}
String Character::operator*(Integer v) {
    // temp value
    std::string temp = "";

    for (int i=0; i<v.value; i++) {
        temp+=value;
    }

    return String(temp);
}
Character Character::operator*(Boolean v) {
    return v.value ? Character(value) : Character();
}
