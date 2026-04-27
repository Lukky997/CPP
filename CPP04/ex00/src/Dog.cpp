#include "../includes/Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "*Woaf*" << std::endl;
}
