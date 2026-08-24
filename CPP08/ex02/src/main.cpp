#include "MutantStack.hpp"

#include <iostream>
#include <stack>

int main(void)
{
	int errors = 0;

	std::cout << "==============================================" << std::endl;
	std::cout << "            MUTANT STACK TESTS" << std::endl;
	std::cout << "==============================================" << std::endl;

	std::cout << "\n=== TEST 1: Stack operations ===" << std::endl;
	{
		MutantStack<int> stack;
		stack.push(5);
		stack.push(17);

		std::cout << "Top: " << stack.top() << std::endl;
		stack.pop();
		std::cout << "Size after pop: " << stack.size() << std::endl;

		stack.push(3);
		stack.push(5);
		stack.push(737);
		stack.push(0);

		if (stack.top() == 0 && stack.size() == 5)
			std::cout << "[OK] Stack operations work" << std::endl;
		else {
			std::cout << "[KO] Stack operations are incorrect" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 2: Forward iteration ===" << std::endl;
	{
		MutantStack<int> stack;
		stack.push(5);
		stack.push(17);
		stack.push(3);
		stack.push(5);
		stack.push(737);
		stack.push(0);

		int expected[] = {5, 17, 3, 5, 737, 0};
		unsigned int index = 0;

		for (MutantStack<int>::iterator it = stack.begin();
			it != stack.end(); ++it, ++index) {
			std::cout << *it << " ";
			if (index >= 6 || *it != expected[index])
				errors++;
		}
		std::cout << std::endl;

		if (index == 6)
			std::cout << "[OK] Forward iterators work" << std::endl;
		else
			std::cout << "[KO] Forward iteration is incorrect" << std::endl;
	}

	std::cout << "\n=== TEST 3: Reverse iteration ===" << std::endl;
	{
		MutantStack<int> stack;
		stack.push(1);
		stack.push(2);
		stack.push(3);

		int expected[] = {3, 2, 1};
		unsigned int index = 0;

		for (MutantStack<int>::reverse_iterator it = stack.rbegin();
			it != stack.rend(); ++it, ++index) {
			std::cout << *it << " ";
			if (index >= 3 || *it != expected[index])
				errors++;
		}
		std::cout << std::endl;

		if (index == 3)
			std::cout << "[OK] Reverse iterators work" << std::endl;
		else
			std::cout << "[KO] Reverse iteration is incorrect" << std::endl;
	}

	std::cout << "\n=== TEST 4: Const iteration ===" << std::endl;
	{
		MutantStack<int> mutableStack;
		mutableStack.push(10);
		mutableStack.push(20);
		mutableStack.push(30);
		const MutantStack<int> stack(mutableStack);
		int total = 0;

		for (MutantStack<int>::const_iterator it = stack.begin();
			it != stack.end(); ++it)
			total += *it;

		std::cout << "Sum: " << total << std::endl;
		if (total == 60)
			std::cout << "[OK] Const iterators work" << std::endl;
		else {
			std::cout << "[KO] Const iteration is incorrect" << std::endl;
			errors++;
		}
	}

	std::cout << "\n=== TEST 5: Copy and compatibility with std::stack ===" << std::endl;
	{
		MutantStack<int> original;
		original.push(42);
		original.push(84);

		MutantStack<int> copy(original);
		std::stack<int> standardStack(original);
		copy.pop();

		if (original.size() == 2 && copy.size() == 1
			&& standardStack.top() == 84)
			std::cout << "[OK] Copy and std::stack compatibility work" << std::endl;
		else {
			std::cout << "[KO] Copy or std::stack compatibility is incorrect" << std::endl;
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