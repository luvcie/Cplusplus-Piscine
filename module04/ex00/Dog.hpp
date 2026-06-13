#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

// to inherit "keep the parents public things public in the child"
class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog &other);
    Dog & operator=(const Dog &other);
    ~Dog();
    // method
    void makeSound() const;
};

#endif
