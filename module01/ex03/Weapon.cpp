#include "Weapon.hpp"

// constructor
Weapon::Weapon(std::string type) : type(type) {
}

const std::string& Weapon::getType() const {
    return type;
}

// "this" is a pointer to the current object, and is used to avoid name clash since both are named type
// without "this", type = type assigns the parameter to itself
// but with it, type->this says "the Member beloonging to this Weapon."
// this = the pointer (points at the current object)
// -> = "follow this pointer to reach a member"
// type = the member
void Weapon::setType(std::string type) {
    this->type = type;
}
