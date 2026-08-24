#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>

bool isValidNumber(char *str) {

	if (!str[0])
		return false;
	for (int i = 0; str[i]; i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool parseNumber(char *str, int &number) {
	char *end;
	unsigned long value;

	errno = 0;
	value = std::strtoul(str, &end, 10);
	if (errno == ERANGE || *end != '\0' || value > INT_MAX)
		return false;
	number = static_cast<int>(value);
	return true;
}

bool isSorted(std::vector<int> const &sequence) {
	for (size_t i = 1; i < sequence.size(); i++) {
		if (sequence[i - 1] > sequence[i])
			return false;
	}
	return true;
}

int main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Error: provide at least one positive integer" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < ac; i++) {

			if (!isValidNumber(av[i])) {
				std::cerr << "Error: invalid number => " << av[i] << std::endl;
        	return 1;
    	}

			int num;
			if (!parseNumber(av[i], num)) {
				std::cerr << "Error: number is out of int range => " << av[i] << std::endl;
			return 1;
		}
		vec.push_back(num);
		deq.push_back(num);
	}

	PmergeMe sorter;

	std::cout << "Before: ";

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	clock_t start = clock();
	sorter.sortWithVector(vec);
	clock_t end = clock();
	double timeVec = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	sorter.sortWithDeque(deq);
	end = clock();
	double timeDeq = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;

	if (!isSorted(vec)) {
		std::cerr << "Error: vector is not sorted" << std::endl;
		return 1;
	}
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i] != deq[i]) {
			std::cerr << "Error: vector and deque results differ" << std::endl;
			return 1;
		}
	}

    return 0;
}