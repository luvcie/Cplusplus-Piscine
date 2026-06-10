#include "Fixed.hpp"

// flow
// everything is stored as one int = real number * 256 (256 because 8 fractional bits, 2^8)
// storing shifts LEFT (* 256), reading back shifts RIGHT (/ 256), they are inverses
//
// 1. Fixed a               default ctor, value = 0
// 2. Fixed const b(10)     int ctor: value = 10 << 8 (left shift = * 256) = 2560
// 3. Fixed const c(42.42f) float ctor: can't shift a float, so value = round(42.42 * 256) = 10860
// 4. Fixed const d(b)      copy ctor, copies b's raw value into d
// 5. a = Fixed(1234.4321f) float ctor builds a temp (round(1234.4321 * 256)), operator= copies it into a, temp dies
// 6. cout << a/b/c/d        operator<< calls toFloat: value / 256 (cast to float keeps the decimals) -> 1234.43, 10, 42.4219, 10
// 7. a/b/c/d .toInt()       toInt: value >> 8 (right shift = / 256), integer so it truncates -> 1234, 10, 42, 10
//
// so: ctors push the number in by shifting left (* 256), toFloat and toInt pull it back out by shifting/dividing right (/ 256)

int main(void) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f); // the f tells the compiler that it's a float
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

/*
    // test 1: int ctor stores n * 256
    Fixed five(5);
    std::cout << five.getRawBits() << std::endl; // expected: 1280 (5 * 256)
    std::cout << five.toInt() << std::endl;       // expected: 5
    std::cout << five.toFloat() << std::endl;     // expected: 5

    // test 2: float ctor rounds (0.5 * 256 = 128 exactly)
    Fixed half(0.5f);
    std::cout << half.getRawBits() << std::endl;  // expected: 128
    std::cout << half.toFloat() << std::endl;     // expected: 0.5

    // test 3: toInt truncates, does not round
    Fixed almost(42.99f);
    std::cout << almost.toInt() << std::endl;     // expected: 42 (the .99 is removed, not rounded up)

    // test 4: getRawBits / setRawBits touch the raw int directly
    Fixed raw;
    raw.setRawBits(256);
    std::cout << raw.getRawBits() << std::endl;   // expected: 256
    std::cout << raw.toFloat() << std::endl;      // expected: 1   (256 / 256)

    // test 5: assignment chains (operator= returns *this)
    Fixed x, y, z(9);
    x = y = z;
    std::cout << x.toInt() << " " << y.toInt() << std::endl; // expected: 9 9

    // test 6: operator<< chains (named vars so the ctor messages print before the line, not mid-line)
    Fixed one(1);
    Fixed twoHalf(2.5f);
    std::cout << one << " " << twoHalf << std::endl; // expected: 1 2.5
*/

    return 0;
}
