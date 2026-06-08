#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

// weapon class that has:
// a private attribute type which is a string
// a getType() member func that returns a constant reference to type
// a setType() member func that sets type using the new value passed as a param
class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string type); // ctor
        // const so that the caller cn't modify it with getType
        // without const, returning a non-cost reference would let you write through getType
        // example: if it didn't have const u could do `std::string& getType() = "u have been pwned"; D:
        // that's bc geType() returns a reference to the internal type
        const std::string& getType() const;
        void setType(std::string type);
};

#endif
