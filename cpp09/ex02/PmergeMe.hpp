#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
class PmergeMe
{
	private:
		T container;
		void insertion(T &container, size_t index, const size_t limit);
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &merge);
		std::string mergeInsertion(const std::string &name);
		void printNumbers(const std::string &prefix) const;
		void getNumbers(char *argv[], const size_t &argc);
};

#include "PmergeMe.tpp"
#endif