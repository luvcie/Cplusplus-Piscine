#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

// HumanA takes the weapon in its constructor
class HumanA {
    private:
        std::string name;
        // aliases have two hard rules: 1. must be bound when created (can't exist pointing at nothing)
        // 2. can't be reseated/made to point at something else
        // SO HumanA is always armed because it holds a reference to the weapon :D
        Weapon& weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack();
};

#endif
