#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private :
		int value;
		static const int fractional_bits = 8;
	
	public :
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		Fixed(const int num);
		Fixed(const float num);
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif