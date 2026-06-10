#include "Fixed.hpp"
#include <cmath> // for roundf to round a float to the nearest whole number

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// shift left by 8 to make room for the fractional bits
// the n << fractionalBits multiplies by ×256 through bit shift black magick
Fixed::Fixed(const int n) : value(n << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// multiply by 256 then round to the nearest raw value
Fixed::Fixed(const float floatie) : value(roundf(floatie * (1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// gives back the stored int as in the raw value
// puts the int into value when returning
int Fixed::getRawBits() const {
    return this->value;
}

// puts raw into into value without conversion (no *256)
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// raw is value * 256, so divide by 256 to get the real number back
// cast to float first or it'd be integer division and lose the fraction
float Fixed::toFloat() const {
    return (float)this->value / (1 << fractionalBits);
}

// >> 8 = divide by 256, integer division so it drops the fraction (truncates)
// 42.67 truncated -> 42
int Fixed::toInt() const {
    return this->value >> fractionalBits;
}

// prints the float value of the fixed point number
// OVERLOAD of << so that it knows how to print a Fixed
// returns: a stream, cout itself, for chaining ! as a reference because it needs
// to be the same cout, and not a copy
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
