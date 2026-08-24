#include "Array.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 750

int main(void)
{
	int errors = 0;

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "\n=== TEST 1: Default construction ===" << std::endl;
	{
		Array<int> empty;

		std::cout << "Size: " << empty.size() << std::endl;
		if (empty.size() == 0)
			std::cout << "[OK] Empty array has size 0" << std::endl;
		else {
			std::cout << "[KO] Invalid empty array size" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 2: Construction with a size ===" << std::endl;
	{
		Array<int> numbers(5);
		bool initialized = true;

		std::cout << "Size: " << numbers.size() << std::endl;
		std::cout << "Default values: ";
		for (unsigned int index = 0; index < numbers.size(); index++) {
			std::cout << numbers[index] << " ";
			if (numbers[index] != 0)
				initialized = false;
		}
		std::cout << std::endl;

		if (numbers.size() == 5 && initialized)
			std::cout << "[OK] Size and default values are correct" << std::endl;
		else {
			std::cout << "[KO] Invalid size or default values" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 3: Initialization and values ===" << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int mirror[MAX_VAL];

		for (unsigned int index = 0; index < MAX_VAL; index++) {
			const int value = std::rand();
			numbers[index] = value;
			mirror[index] = value;
		}

		bool sameValues = true;
		for (unsigned int index = 0; index < MAX_VAL; index++) {
			if (numbers[index] != mirror[index]) {
				sameValues = false;
				break;
			}
		}

		std::cout << "Size: " << numbers.size() << std::endl;
		if (numbers.size() == MAX_VAL && sameValues)
			std::cout << "[OK] All values were stored correctly" << std::endl;
		else {
			std::cout << "[KO] Values were not stored correctly" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 4: Modification of elements ===" << std::endl;
	{
		Array<int> numbers(5);

		for (unsigned int index = 0; index < numbers.size(); index++)
			numbers[index] = static_cast<int>(index * 10);

		std::cout << "Modified values: ";
		for (unsigned int index = 0; index < numbers.size(); index++)
			std::cout << numbers[index] << " ";
		std::cout << std::endl;

		if (numbers[0] == 0 && numbers[1] == 10 && numbers[2] == 20
			&& numbers[3] == 30 && numbers[4] == 40)
			std::cout << "[OK] Elements can be modified" << std::endl;
		else {
			std::cout << "[KO] Element modification is incorrect" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 5: Deep copy ===" << std::endl;
	{
		Array<int> original(3);
		original[0] = 10;
		original[1] = 20;
		original[2] = 30;

		Array<int> copy(original);
		copy[0] = 100;

		if (original[0] == 10 && copy[0] == 100
			&& copy[1] == 20 && copy[2] == 30)
			std::cout << "[OK] Copy is independent from original" << std::endl;
		else {
			std::cout << "[KO] Copy shares data with original" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 6: Assignment operator ===" << std::endl;
	{
		Array<std::string> original(2);
		original[0] = "first";
		original[1] = "second";

		Array<std::string> assigned;
		assigned = original;
		assigned[0] = "changed";

		if (original[0] == "first" && assigned[0] == "changed"
			&& assigned[1] == "second")
			std::cout << "[OK] Assignment performs a deep copy" << std::endl;
		else {
			std::cout << "[KO] Assignment is incorrect" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 7: Bounds checking ===" << std::endl;
	{
		Array<int> numbers(3);
		bool lowerBoundCaught = false;
		bool upperBoundCaught = false;

		try {
			numbers[-2] = 0;
		} catch (const std::exception &exception) {
			lowerBoundCaught = true;
			std::cout << "Lower bound: " << exception.what() << std::endl;
		}

		try {
			numbers[3] = 0;
		} catch (const std::exception &exception) {
			upperBoundCaught = true;
			std::cout << "Upper bound: " << exception.what() << std::endl;
		}

		if (lowerBoundCaught && upperBoundCaught)
			std::cout << "[OK] Out-of-range accesses throw exceptions" << std::endl;
		else {
			std::cout << "[KO] Bounds checking is incomplete" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 8: Array<std::string> and const access ===" << std::endl;
	{
		Array<std::string> values(3);
		values[0] = "Hello";
		values[1] = "World";
		values[2] = "!";
		const Array<std::string> constValues(values);

		std::cout << "Values: " << constValues[0] << " "
			<< constValues[1] << " " << constValues[2] << std::endl;
		if (constValues[0] == "Hello" && constValues[1] == "World"
			&& constValues[2] == "!")
			std::cout << "[OK] String values and const access work" << std::endl;
		else {
			std::cout << "[KO] Const access is incorrect" << std::endl;
			errors++;
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