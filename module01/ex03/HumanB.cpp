#include "HumanB.hpp"
#include <iostream>

// start without weapon, pointer to null
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
}

// store address of weapon to point at caller's real object
void HumanB::setWeapon(Weapon& weapon){
   this->weapon = &weapon;
}

void HumanB::attack() {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}
