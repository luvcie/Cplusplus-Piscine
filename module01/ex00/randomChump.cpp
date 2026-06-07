#include "Zombie.hpp"

// stack one: this zombie is only used inside the function so i dont use new
// announces and dies automatically when function ends, destructor runs on its own
void randomChump(std::string name) {
    Zombie chump(name);
    chump.announce();
}
