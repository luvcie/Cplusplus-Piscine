#include "Zombie.hpp"

// store name when zombie is built
Zombie::Zombie(std::string name) : name (name) {
}

// destructor prints name to see when each zombie is freed
// the stack randomchump will die by itself, and the heap zombie made with newZombie when i delete it manually
Zombie::~Zombie() {
    std::cout << name << " burned to death" << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
