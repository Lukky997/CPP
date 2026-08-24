#include "Span.hpp"

#include <iostream>
#include <vector>

int main(void)
{
	int errors = 0;

	std::cout << "\n=== TEST 1: Basic span ===" << std::endl;
	{
		Span span(5);
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);

		std::cout << "Size: " << span.size() << std::endl;
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;

		if (span.shortestSpan() == 2 && span.longestSpan() == 14)
			std::cout << "[OK] Span calculations are correct" << std::endl;
		else {
			std::cout << "[KO] Span calculations are incorrect" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 2: Add a range of numbers ===" << std::endl;
	{
		Span span(10);
		std::vector<int> values;

		values.push_back(1);
		values.push_back(100);
		values.push_back(50);
		values.push_back(-20);

		span.addRange(values.begin(), values.end());
		std::cout << "Size after range insertion: " << span.size() << std::endl;
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;

		if (span.size() == 4 && span.shortestSpan() == 21
			&& span.longestSpan() == 120)
			std::cout << "[OK] Range insertion works" << std::endl;
		else {
			std::cout << "[KO] Range insertion is incorrect" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 3: Capacity limit ===" << std::endl;
	{
		Span span(2);
		span.addNumber(10);
		span.addNumber(20);

		try {
			span.addNumber(30);
			std::cout << "[KO] No exception was thrown" << std::endl;
			errors++;
		} catch (const std::exception &exception) {
			std::cout << "Exception caught: " << exception.what() << std::endl;
			std::cout << "[OK] Full span rejects new numbers" << std::endl;
		}
	}

	std::cout << "\n=== TEST 4: Range exceeding capacity ===" << std::endl;
	{
		Span span(3);
		std::vector<int> values;
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		values.push_back(4);

		try {
			span.addRange(values.begin(), values.end());
			std::cout << "[KO] No exception was thrown" << std::endl;
			errors++;
		} catch (const std::exception &exception) {
			std::cout << "Exception caught: " << exception.what() << std::endl;
			if (span.size() == 0)
				std::cout << "[OK] Range was not partially inserted" << std::endl;
			else {
				std::cout << "[KO] Range was partially inserted" << std::endl;
				errors++;
			}
		}
	}

	std::cout << "\n=== TEST 5: Copy construction and assignment ===" << std::endl;
	{
		Span original(4);
		original.addNumber(5);
		original.addNumber(15);
		original.addNumber(25);

		Span copy(original);
		Span assigned(1);
		assigned = original;

		copy.addNumber(100);
		if (original.size() == 3 && copy.size() == 4
			&& assigned.size() == 3
			&& original.shortestSpan() == 10
			&& assigned.longestSpan() == 20)
			std::cout << "[OK] Copy and assignment preserve the data" << std::endl;
		else {
			std::cout << "[KO] Copy or assignment is incorrect" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 6: Not enough numbers ===" << std::endl;
	{
		Span span(1);
		span.addNumber(42);
		bool shortestCaught = false;
		bool longestCaught = false;

		try {
			span.shortestSpan();
		} catch (const std::exception &exception) {
			shortestCaught = true;
			std::cout << "Shortest span exception: " << exception.what() << std::endl;
		}

		try {
			span.longestSpan();
		} catch (const std::exception &exception) {
			longestCaught = true;
			std::cout << "Longest span exception: " << exception.what() << std::endl;
		}

		if (shortestCaught && longestCaught)
			std::cout << "[OK] Invalid span calculations throw exceptions" << std::endl;
		else {
			std::cout << "[KO] Missing exception for an invalid span" << std::endl;
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