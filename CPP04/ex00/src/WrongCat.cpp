#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = copy._type;
}

WrongCat &WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &copy) {
		WrongAnimal::operator=(copy);
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "*WrongCat: Meow*" << std::endl;
}
