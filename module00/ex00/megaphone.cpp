// cctype is for toupper, iostream for cout and endl
#include <cctype>
#include <iostream>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    for (int i = 1; i < argc; ++i) {
        char *str = argv[i];
        while (*str != 0) {
            // toupper returns an int, so it needs to be casted with the static_cast template which checks
            // at compile time, and dynamic_cast would check at runtime.
            // the type you cast to is put inside the < > symbols.
            // cast to unsigned char first: char is signed, so high bytes (emoji, accents...)
            // would be negative and toupper on a negative value is undefined behaviour
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(*str)));
            ++str;
        }
    }
    // :: is just "look inside this namespace/scope for the thing on the right", like cout and endl :P
    std::cout << std::endl;
    return 0;
}
// i'm so happy that there's no norminette anymore and i can put comments inside functions YAY
