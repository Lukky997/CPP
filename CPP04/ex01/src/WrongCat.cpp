#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "*WrongCat: Meow*" << std::endl;
}
