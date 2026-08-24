#include "Serializer.hpp"

int main(void)
{
	int errors = 0;

	std::cout << "\n=== TEST 1: Object on the stack ===" << std::endl;
	{
		Data original(42, "Stack Object");
		uintptr_t raw = Serializer::serialize(&original);
		Data *deserialized = Serializer::deserialize(raw);

		std::cout << "Original address      : " << &original << std::endl;
		std::cout << "Serialized value      : " << raw << std::endl;
		std::cout << "Deserialized address  : " << deserialized << std::endl;
		std::cout << "Original data         : " << original.value
			<< ", " << original.name << std::endl;

		if (deserialized == &original) {
			std::cout << "[OK] Pointers are equal" << std::endl;
		} else {
			std::cout << "[KO] Pointers are different" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 2: Object on the heap ===" << std::endl;
	{
		Data *original = new Data(100, "Heap Object");
		uintptr_t raw = Serializer::serialize(original);
		Data *deserialized = Serializer::deserialize(raw);

		std::cout << "Original address      : " << original << std::endl;
		std::cout << "Serialized value      : " << raw << std::endl;
		std::cout << "Deserialized address  : " << deserialized << std::endl;
		std::cout << "Deserialized data     : " << deserialized->value
			<< ", " << deserialized->name << std::endl;

		if (deserialized == original) {
			std::cout << "[OK] Pointers are equal" << std::endl;
		} else {
			std::cout << "[KO] Pointers are different" << std::endl;
			errors++;
		}
		delete original;
	}

	std::cout << "\n=== TEST 3: Default constructor ===" << std::endl;
	{
		Data original;
		uintptr_t raw = Serializer::serialize(&original);
		Data *deserialized = Serializer::deserialize(raw);

		std::cout << "Original address      : " << &original << std::endl;
		std::cout << "Serialized value      : " << raw << std::endl;
		std::cout << "Deserialized address  : " << deserialized << std::endl;
		std::cout << "Deserialized data     : " << deserialized->value
			<< ", " << deserialized->name << std::endl;

		if (deserialized == &original) {
			std::cout << "[OK] Pointers are equal" << std::endl;
		} else {
			std::cout << "[KO] Pointers are different" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 4: Multiple objects ===" << std::endl;
	{
		Data first(1, "First");
		Data second(2, "Second");
		Data third(3, "Third");

		uintptr_t firstRaw = Serializer::serialize(&first);
		uintptr_t secondRaw = Serializer::serialize(&second);
		uintptr_t thirdRaw = Serializer::serialize(&third);

		Data *firstPtr = Serializer::deserialize(firstRaw);
		Data *secondPtr = Serializer::deserialize(secondRaw);
		Data *thirdPtr = Serializer::deserialize(thirdRaw);

		std::cout << "first  : " << firstPtr << " (value="
			<< firstPtr->value << ")" << std::endl;
		std::cout << "second : " << secondPtr << " (value="
			<< secondPtr->value << ")" << std::endl;
		std::cout << "third  : " << thirdPtr << " (value="
			<< thirdPtr->value << ")" << std::endl;

		if (firstPtr == &first && secondPtr == &second && thirdPtr == &third) {
			std::cout << "[OK] All pointers are equal to their originals" << std::endl;
		} else {
			std::cout << "[KO] At least one pointer is incorrect" << std::endl;
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
