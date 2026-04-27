#include "../includes/Animal.hpp"

Animal::Animal() {
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	_type = copy._type;
}

Animal &Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->_type = copy._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return (_type);
}

void Animal::makeSound() const {
	std::cout << "*Make a sound*" << std::endl;
}
