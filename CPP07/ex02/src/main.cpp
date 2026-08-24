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

	std::cout << "\n=== TEST 2: Initialization and values ===" << std::endl;
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

	std::cout << "\n=== TEST 3: Deep copy ===" << std::endl;
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

	std::cout << "\n=== TEST 4: Assignment operator ===" << std::endl;
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

	std::cout << "\n=== TEST 5: Bounds checking ===" << std::endl;
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

	std::cout << "\n=== TEST 6: Const access ===" << std::endl;
	{
		Array<int> values(2);
		values[0] = 7;
		values[1] = 11;
		const Array<int> constValues(values);

		if (constValues[0] == 7 && constValues[1] == 11)
			std::cout << "[OK] Const access works" << std::endl;
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