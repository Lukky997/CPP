#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();

		static bool isChar(std::string const &str);
		static bool isInt(std::string const &str);
		static bool isFloat(std::string const &str);
		static bool isDouble(std::string const &str);
		static bool isPseudoLiteral(std::string const &str);

		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value);
		static void printDouble(double value);

	public:
		static void convert(std::string const &literal);
};

#endif