#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string name); // constructor, runs when a zombie is born, stores its name
        ~Zombie(); // destructor, destructors have ~ prefix and no return or parameters, runs when zombie dies
        void announce();
};

Zombie* newZombie(std::string name); // makes a zombie on HEAP, returns it
void randomChump(std::string name); // makes zombie on STACK, announces it

#endif
