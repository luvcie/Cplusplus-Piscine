#include "Fixed.hpp"

int main(void) {
    std::cout << std::endl;
    Fixed a; // default constructor called: a.value = 0
    Fixed b(a); // copy ctor called: b is built from a, value copied
    Fixed c; // default constructor called again: value of c = 0
    std::cout << std::endl;

    c = b;  // the operator= is called: c already exists, b is assigned into it
            // (different from copy ctor, c was already born)
    std::cout << std::endl;

    // getRawBits() reads the raw int that is in value (without dividing/converting)
    // all 3 print 0 because nothing changed the raw value
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    std::cout << "all these messages are for debugging" << std::endl;

/*
    // test 1: setRawBits + getRawBits
    a.setRawBits(256);
    std::cout << a.getRawBits() << std::endl; // expected: 256

    // test 2: self-assignment
    a.setRawBits(0);
    a = a;
    std::cout << a.getRawBits() << std::endl; // expected: 0

    // test 3: chaining
    a.setRawBits(128);
    c = b = a;
    std::cout << b.getRawBits() << std::endl; // expected: 128
    std::cout << c.getRawBits() << std::endl; // expected: 128

    // test 4: copy independence (checks htat a copy is its own object)
    a.setRawBits(999);
    Fixed d(a);
    a.setRawBits(0);
    std::cout << d.getRawBits() << std::endl; // expected: 999

    // test 5: const object
    Fixed const e(a);
    std::cout << e.getRawBits() << std::endl; // expected: 0
*/

    return 0; // when main ends all 3 objects go out of scope and the destructor is called for each :3
    // the destructors called right after main exits can be seen in the terminal output !
}

/* flow
1. Fixed a;
default ctor runs and sets a.value to 0
2. Fixed b(a);
copy ctor runs and calls the operator= internally
operator= copies a.value into b.value
b.value becomes 0
3. Fixed c;
the default contructor runs and sets c value to 0
4. c = b;
operator= runs directly (c already exists)
copies b.value into c.value
c.value = 0
5. getRawBits() called 3 times
prints internal raw integer for a, b and c
which is 0 so they all print 0
6. main ends and objects die and dtor runs yeayayay
 */
