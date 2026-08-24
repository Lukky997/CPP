#include "easyfind.hpp"

#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	int errors = 0;

	std::cout << "\n=== TEST 1: Find a value in a vector ===" << std::endl;
	{
		std::vector<int> numbers;
		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);

		try {
			std::vector<int>::iterator result = easyfind(numbers, 30);
			std::cout << "Found value: " << *result << std::endl;
			if (*result == 30)
				std::cout << "[OK] Correct value found" << std::endl;
			else {
				std::cout << "[KO] Wrong value found" << std::endl;
				errors++;
			}
		} catch (const std::exception &exception) {
			std::cout << "[KO] Unexpected exception: "
				<< exception.what() << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 2: Value not found ===" << std::endl;
	{
		std::vector<int> numbers;
		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(3);

		try {
			easyfind(numbers, 99);
			std::cout << "[KO] No exception was thrown" << std::endl;
			errors++;
		} catch (const std::exception &exception) {
			std::cout << "Exception caught: " << exception.what() << std::endl;
			std::cout << "[OK] Missing value is correctly rejected" << std::endl;
		}
	}

	std::cout << "\n=== TEST 3: Find a value in a list ===" << std::endl;
	{
		std::list<int> numbers;
		numbers.push_back(5);
		numbers.push_back(15);
		numbers.push_back(25);

		try {
			std::list<int>::iterator result = easyfind(numbers, 5);
			std::cout << "Found value: " << *result << std::endl;
			if (*result == 5)
				std::cout << "[OK] List is supported" << std::endl;
			else {
				std::cout << "[KO] Wrong value found" << std::endl;
				errors++;
			}
		} catch (const std::exception &exception) {
			std::cout << "[KO] Unexpected exception: "
				<< exception.what() << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 4: Find a value in a deque ===" << std::endl;
	{
		std::deque<int> numbers;
		numbers.push_back(7);
		numbers.push_back(14);
		numbers.push_back(21);

		try {
			std::deque<int>::iterator result = easyfind(numbers, 14);
			std::cout << "Found value: " << *result << std::endl;
			if (*result == 14)
				std::cout << "[OK] Deque is supported" << std::endl;
			else {
				std::cout << "[KO] Wrong value found" << std::endl;
				errors++;
			}
		} catch (const std::exception &exception) {
			std::cout << "[KO] Unexpected exception: "
				<< exception.what() << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 5: Empty container ===" << std::endl;
	{
		std::vector<int> empty;

		try {
			easyfind(empty, 0);
			std::cout << "[KO] No exception was thrown" << std::endl;
			errors++;
		} catch (const std::exception &exception) {
			std::cout << "Exception caught: " << exception.what() << std::endl;
			std::cout << "[OK] Empty container is correctly handled" << std::endl;
		}
	}

	std::cout << "\n==============================================" << std::endl;
	if (errors == 0) {
		std::cout << "All tests passed." << std::endl;
		return 0;
	}
	std::cout << errors << " test(s) failed." << std::endl;
	return 1;
}
