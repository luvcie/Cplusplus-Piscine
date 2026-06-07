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

## module 01

memory allocation, pointers to members, references and switch statements.

concepts:
- the stack vs the heap. stack is automatic, freed when it goes out of scope. the heap is manual, you ask for it with `new` and you must give it back with `delete` or it leaks. [new and delete](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
- arrays on the heap with `new type[n]`, freed with `delete[]` (the brackets matter, plain `delete` on an array is wrong). [dynamic arrays](https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/)
- a reference is an alias for an existing variable. it must be initialized when declared and can't be made to point somewhere else after. a pointer can be null and can be reseated. [references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
- rule of thumb for members: if the thing is always there use a reference, if it might be missing use a pointer.
- a member function returning a `const` reference hands back the real attribute without a copy and without letting the caller change it. [return by reference](https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/)
- pointers to member functions: store which method to call in a variable instead of a big if/else, declared `void (Harl::*f)()` and called with `(this->*f)()`. [pointers to members](https://isocpp.org/wiki/faq/pointers-to-members)
- file streams `std::ifstream` and `std::ofstream` to read and write files the c++ way, no `fopen`. [fstream](https://cplusplus.com/reference/fstream/)
- the `switch` statement as an alternative to a chain of if/else. [switch](https://www.learncpp.com/cpp-tutorial/switch-statement-basics/)

### ex00 braiiiiiiinnnzzzz

a `Zombie` class that announces itself, the point is choosing stack or heap.
- `newZombie` makes a zombie that outlives the function, so it goes on the heap and is returned as a pointer
- `randomChump` only needs the zombie inside the function, so it goes on the stack and dies on its own
- the destructor prints the name so you can see when each one is freed

### ex01 moar brainz!

`zombieHorde(int n, std::string name)` allocates n zombies in one `new[]`.
- one allocation for the whole horde, not a loop of `new`
- returns a pointer to the first zombie, freed later with `delete[]`

### ex02 hi this is brain

prints addresses and values of a string through a pointer and a reference.
- shows the address is the same whether you go through the variable, the pointer or the reference
- a reference really is just another name for the same memory

### ex03 unnecessary violence

a `Weapon` shared by two humans.
- `HumanA` always has a weapon, so it holds a reference
- `HumanB` might not, so it holds a pointer that can be null
- `getType` returns a const reference so the weapon type isn't copied

### ex04 sed is for losers

replaces every occurrence of one string with another in a file.
- reads with `std::ifstream`, writes to `<filename>.replace` with `std::ofstream`
- `std::string::replace` is forbidden, so the swap is done with `find` and `substr`

### ex05 harl 2.0

a `Harl` that complains at four levels.
- the four messages are private member functions
- `complain` picks which one to call with an array of pointers to member functions, no if/else forest
