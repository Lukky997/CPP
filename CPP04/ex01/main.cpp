#include <iostream>

#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int main()
{
  const int n = 10;
  Animal *animals[n];

  for (int i = 0; i < n; i++)
  {
    if (i < n / 2)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }

  std::cout << "\nDeleting as Animals" << std::endl;
  for (int i = 0; i < n; i++)
    delete animals[i];

  std::cout << "\nDeep copy test" << std::endl;
  Dog original;
  original.getBrain()->setIdea(0, "Ball");
  Dog copy(original);
  original.getBrain()->setIdea(0, "Bone");
  std::cout << "original idea[0] = " << original.getBrain()->getIdea(0) << std::endl;
  std::cout << "copy idea[0]     = " << copy.getBrain()->getIdea(0) << std::endl;

  return 0;
}
