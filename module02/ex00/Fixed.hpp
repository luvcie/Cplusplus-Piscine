#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// a fixed point number is a regular int, but we pretend that the last 8 bits are a fractional part
// so the actual stored integer is always (real_value * 256)
// example: real number 1.0 is stored as 256. 0.5 is stored as 128.
// 1.0 is never stored directly, just the scaled integer (256)
// an int is 32 bits [24 high bits][8 low bits]
// stored bits: 00000000 00000000 00000001 00000000 CPU sees this as 256, and we decide it means 1 by by remembering to divide by 256 when reading it
// (256 as a normal int) (but as fixed point it's 1.0 bc 256/256 = 1.0)
class Fixed {
    private:
        int value;
        static const int fractionalBits = 8; // not used anywhere but the PDF asks for it xd
    public:
        // Orthodox Canonical Form is a rule that says every class must have these 4 canonical functions:
        Fixed();                             // 1. default ctor: makes a Fixed = 0
        Fixed(const Fixed& other);           // 2. COPY ctor: builds a Fixed from an existing Fixed
        Fixed& operator=(const Fixed& other);// 3. COPY Assignment: copies into an already existing Fixed (OPERATOR OVERLOAD)
        ~Fixed();                            // 4. dtor

        int getRawBits() const; // getter
        void setRawBits(int const raw); // setter
};

#endif
