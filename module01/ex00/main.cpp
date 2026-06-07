#include "Zombie.hpp"

int main(){
    // heap zombie, get pointer back from newZombie, use it and delete
    Zombie* heapie = newZombie("HeapZombieGuy");
    heapie->announce();
    delete heapie;

    // stack zombie, creates annoucnes and fees itself
    randomChump("StackZombieGirliePop");

    return 0;
}

// did you know ?! ^D^ the stack is for local variables funcs params return addresses, registers etc and it's pretty fast and small, around 8mb
// and the heap is a big pool and it's slower and have to get memory and give back what you take, the heap is most of RAM
