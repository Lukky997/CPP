#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


class	PmergeMe {
	private :
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	generateJacobsthal(int n);
		std::vector<int>	getInsertionOrder(int n);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &copy);
		~PmergeMe();

		void	sortWithVector(std::vector<int> &seq);
		void	sortWithDeque(std::deque<int> &seq);
};

#endif