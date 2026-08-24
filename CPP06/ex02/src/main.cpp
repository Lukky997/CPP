#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void);
void identify(Base *ptr);
void identify(Base &ptr);

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "\n=== TEST 1: Identify each type by pointer ===" << std::endl;
	{
		A objectA;
		B objectB;
		C objectC;

		std::cout << "A object: ";
		identify(&objectA);
		std::cout << "B object: ";
		identify(&objectB);
		std::cout << "C object: ";
		identify(&objectC);
	}

	std::cout << "\n=== TEST 2: Identify each type by reference ===" << std::endl;
	{
		A objectA;
		B objectB;
		C objectC;

		std::cout << "A object: ";
		identify(objectA);
		std::cout << "B object: ";
		identify(objectB);
		std::cout << "C object: ";
		identify(objectC);
	}

	std::cout << "\n=== TEST 3: Generated objects ===" << std::endl;
	for (int index = 0; index < 10; index++) {
		Base *object = generate();

		std::cout << "Object " << index + 1 << " by pointer:   ";
		identify(object);
		std::cout << "Object " << index + 1 << " by reference: ";
		identify(*object);

		delete object;
	}

	std::cout << "\n=== TEST 4: Null pointer ===" << std::endl;
	std::cout << "Null object: ";
	identify(static_cast<Base *>(NULL));

	std::cout << "\n==============================================" << std::endl;
	std::cout << "All tests completed." << std::endl;
	return 0;
}