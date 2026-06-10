#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // std::cout is an ostream/output stream

class Fixed {
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed(); // canonical default constructor, value = 0
        Fixed(const int n);   // int -> fixed, int constructor (value = n * 256)
        Fixed(const float floatie); // float -> fixed, float constructor ( n.n * 256)
        Fixed(const Fixed& other); // copy constructor like if u do Fixed d(a) it copies a's value
        Fixed & operator=(const Fixed& other); // copy into an existing Fixed, returns *this by ref so a = b = c chains
        ~Fixed();

        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;
};

// prints the float value of the fixed point number
// OVERLOAD of << so that it knows how to print a Fixed
// returns: a stream, cout itself, for chaining ! as a reference because it needs
// to be the same cout, and not a copy
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
