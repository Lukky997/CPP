#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"

#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main() {
	const Animal* h = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	h->makeSound();
	j->makeSound();
	i->makeSound();

	delete h;
	delete j;
	delete i;

	std::cout << "\n Test without virtual" << std::endl;

	const WrongAnimal* k = new WrongCat();

	std::cout << k->getType() << " " << std::endl;
	k->makeSound();

	delete k;

	return (0);
}