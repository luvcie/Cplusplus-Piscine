#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  Animal* animals[4];

  animals[0] = new Dog();
  animals[1] = new Cat();
  animals[2] = new Dog();
  animals[3] = new Cat();

  std::cout << "\n--- VIRTUAL (correct) ---" << std::endl;
  for (int i = 0; i < 4; ++i)
    animals[i]->makeSound();

  std::cout << "\n--- getType ---" << std::endl;
  for (int i = 0; i < 4; ++i)
    std::cout << animals[i]->getType() << std::endl;

  for (int i = 0; i < 4; ++i)
    delete animals[i];

  std::cout << "\n--- WRONG (no virtual) ---" << std::endl;
  WrongAnimal* wrong = new WrongCat();
  std::cout << wrong->getType() << std::endl;
  wrong->makeSound();
  delete wrong;
}
