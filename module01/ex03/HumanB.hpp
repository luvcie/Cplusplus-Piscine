#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

// Human B may not always have weapon, can be added one with setWeapon
// so it holds a pointer, and a pointer can be null = unarmed
// a reference could never be null !
class HumanB {
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(std::string name);
        void setWeapon(Weapon& weapon);
        void attack();
};

#endif
