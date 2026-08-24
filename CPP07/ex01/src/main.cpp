#include "Iter.hpp"

#include <iostream>
#include <string>

template <typename T>
void printValue(T const &value)
{
	std::cout << value << " ";
}

void increment(int &value)
{
	value++;
}

int main(void)
{
	std::cout << "\n=== TEST 1: Integer array ===" << std::endl;
	{
		int numbers[] = {1, 2, 3, 4, 5};
		const size_t length = sizeof(numbers) / sizeof(numbers[0]);

		std::cout << "Before: ";
		iter(numbers, length, printValue<int>);
		std::cout << std::endl;

		iter(numbers, length, increment);
		std::cout << "After : ";
		iter(numbers, length, printValue<int>);
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 2: String array ===" << std::endl;
	{
		std::string words[] = {"C++", "templates", "are", "useful"};
		const size_t length = sizeof(words) / sizeof(words[0]);

		std::cout << "Values: ";
		iter(words, length, printValue<std::string>);
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 3: Constant array ===" << std::endl;
	{
		const double values[] = {1.5, 2.5, 3.5};
		const size_t length = sizeof(values) / sizeof(values[0]);

		std::cout << "Values: ";
		iter(values, length, printValue<double>);
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 4: Empty array ===" << std::endl;
	{
		int *empty = NULL;

		iter(empty, 0, printValue<int>);
		std::cout << "Empty array handled correctly." << std::endl;
	}

	std::cout << "\n==============================================" << std::endl;
	std::cout << "All tests completed." << std::endl;
	return 0;
}
