#include <iostream>

#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int main()
{
  std::cout << "Test polymorphisme (classe abstraite)" << std::endl;

  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  std::cout << dog->getType() << " : ";
  dog->makeSound();

  std::cout << cat->getType() << " : ";
  cat->makeSound();

  delete dog;
  delete cat;

  std::cout << "\nTableau d'animaux" << std::endl;

  const int size = 6;
  Animal* animals[size];

  for (int i = 0; i < size; i++) {
    if (i < size / 2)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }

  for (int i = 0; i < size; i++)
    delete animals[i];

  std::cout << "\nTest deep copy" << std::endl;

  Dog original;
  original.getBrain()->setIdea(0, "Manger");

  Dog copy(original);

  std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
  std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;

  copy.getBrain()->setIdea(0, "Dormir");

  std::cout << "\nAprès modification :" << std::endl;
  std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
  std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;

  return 0;
}


