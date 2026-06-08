#include <iostream>
#include <string>

int main() {
    std::string brainvar = "HI THIS IS BRAIN";

    std::string *stringPTR = &brainvar; // holds addrss of str

    // a reference is a second name for a variable, an alias, it's the same memory but can have two names
    // and it's done by putting '&' after the type, if you don't put the & then it's not a reference but a copy
    std::string& stringREF = brainvar;

    std::cout << "Here are the memory addresses that the exercise asks to print:" << std::endl;
    std::cout << &brainvar << std::endl; // memory address of string variable
    std::cout << stringPTR << std::endl; // memory address held by stringPTR
    std::cout << &stringREF << std::endl; // memory address held by stringREF

    std::cout << std::endl << "And here are values that the exercise asks to print:" << std::endl;
    std::cout << brainvar << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    return 0;
}
