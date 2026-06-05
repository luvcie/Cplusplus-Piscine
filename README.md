# c++ piscine

my notes for the 42 c++ modules.

## module 00

introduction to object oriented programming. namespaces, classes, member functions, stdio streams (cin/cout), init lists, static and const.

concepts:
- output with `std::cout << ... << std::endl` instead of printf. outside the piscine i'd still use printf, it's simpler. [streams](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/)
- explicit casting with `static_cast<type>(x)` instead of `(type)x`. [static_cast](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)
- a class is split into a header (`.hpp`) for the declaration and a `.cpp` for the definitions. [header files](https://www.learncpp.com/cpp-tutorial/header-files/)
- private vs public members. [access specifiers](https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/)
- getters and setters: a getter is an accessor that returns a field's value and takes nothing, a setter is a mutator that takes a value and assigns it. [access functions](https://www.learncpp.com/cpp-tutorial/access-functions/)
- init lists set members before the constructor body: `Foo() : x(0) {}`. [member initializer lists](https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/)

### ex00 megaphone

prints the command line arguments in uppercase.
- argv is an array of c strings, the loop starts at 1 to skip the program name
- `toupper` is in `<cctype>` and returns an int, so it is cast back to char. [toupper](https://cplusplus.com/reference/cctype/toupper/)
- `static_cast` is the c++ cast

### ex01 my awesome phonebook

phonebook with a maximum of 8 contacts, no dynamic allocation.
- two classes: `PhoneBook` holds an array of `Contact`
- a 9th contact overwrites the oldest, done with an index wrapped with `% 8`
- getters and setters keep the contact fields private
- table formatting with `<iomanip>`, `std::setw(10)` for the columns, right aligned. [setw](https://cplusplus.com/reference/iomanip/setw/)
- fields longer than 10 chars are cut to 9 and a dot
- input read with `std::getline`, the index string converted to int with `std::istringstream`. [getline](https://cplusplus.com/reference/string/string/getline/), [istringstream](https://cplusplus.com/reference/sstream/istringstream/)
