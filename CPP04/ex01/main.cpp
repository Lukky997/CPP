#include <iostream>

#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"


int main()
{

  const Animal* j = new Dog();
  const Animal* i = new Cat();

  delete j;
  delete i;

  std::cout << "\nTest polymorphisme" << std::endl;

  Animal* animals[4];
  for (int k = 0; k < 4; k++) {
    if (k < 2)
      animals[k] = new Dog();
    else
      animals[k] = new Cat();
  }

  for (int k = 0; k < 4; k++) {
    std::cout << animals[k]->getType() << " : ";
    animals[k]->makeSound();
    }

  for (int k = 0; k < 4; k++)
    delete animals[k];

  std::cout << "\nTest Brain" << std::endl;

  Dog dog;
  dog.getBrain()->setIdea(0, "Courir");
  dog.getBrain()->setIdea(1, "Manger");

  std::cout << "Dog ideas: " << std::endl;
  std::cout << dog.getBrain()->getIdea(0) << std::endl;
  std::cout << dog.getBrain()->getIdea(1) << std::endl;

  std::cout << "\nTest copie" << std::endl;

  Dog copy = dog;

  std::cout << "Avant modification :" << std::endl;
  std::cout << "Original: " << dog.getBrain()->getIdea(0) << std::endl;
  std::cout << "Copy: " << copy.getBrain()->getIdea(0) << std::endl;

  copy.getBrain()->setIdea(0, "Dormir");

  std::cout << "\nAprès modification :" << std::endl;
  std::cout << "Original: " << dog.getBrain()->getIdea(0) << std::endl;
  std::cout << "Copy: " << copy.getBrain()->getIdea(0) << std::endl;

  return 0;
}