#include "include/Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &copy){
		this->value = copy.value;
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

float Fixed::toFloat() const {
	return ((float)this->value / (1 << fractional_bits));
}

int Fixed::toInt() const {
	return (this->value >> fractional_bits);
}


Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	value = num << fractional_bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(num * (1 << fractional_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}