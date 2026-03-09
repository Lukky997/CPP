#include "include/Fixed.hpp"

Fixed::Fixed() : value (0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &copy){
		this->value = copy.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}