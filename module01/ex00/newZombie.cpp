#include "Zombie.hpp"

// heap: this zombie is returned to use somewhere else
// have to use new to give back the pointer and the caller will have to delete
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
