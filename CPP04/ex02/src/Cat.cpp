#include "../includes/Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	_Brain = new Brain();
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy){
	_Brain = new Brain(*copy._Brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
		delete _Brain;
		_Brain = new Brain(*copy._Brain);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _Brain;
}

void Cat::makeSound() const {
	std::cout << "*Meow*" << std::endl;
}

Brain* Cat::getBrain() const {
	return _Brain;
}
