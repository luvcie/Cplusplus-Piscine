#include "Fixed.hpp"

// initializer list, sets value to 0 before constructor runs, part of the canonical first rule of canonicalism :P
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// returns: raw integer (not the real number but the storage)
int Fixed::getRawBits() const { // const at the end means that it promises to not modify the object
    std::cout << "getRawBits member function called" << std::endl;
    return this->value; // value is the raw scaled integer (example 256 means 1, 128 means 0.5)
}

// takes : raw scaled integer (the caller has to pre-scale, so for example pass 256 for 1.0)
// mutates: this-> value. directly overwritten
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// copy constructor
// takes: reference to an existingFixed object to copy from
// returns: nothing, calls operator= to do the copying
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    // keyword this is a pointer to current object, *this dereferences it giving the object itself
    // *this = other means "assign other into the object i am right now."
    *this = other;
}

// OPERATOR OVERLOAD
// takes: reference to an existing Fixed object to copy from
// mutates: this->value, set to other's raw value ()
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    // "this" is a pointer to the current object
    // "&other" is the address of the object being copied from
    // this check prevents "a = a" from breaking things (self-assignment guard)
    if (this != &other) // "this" is a pointer to current object. &other is the address of the object being copied from
        this->value = other.getRawBits(); //getRawBits reads value and returns it
    return *this;
    // returning *this (the reference to current object) allows chaining: a = b = c;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
