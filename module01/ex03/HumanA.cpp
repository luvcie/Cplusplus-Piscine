#include "HumanA.hpp"
#include <iostream>

// constructor
// name(name) weapon(weapon) sets both members
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
