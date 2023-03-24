#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(){}

template <typename T>
PmergeMe<T>::~PmergeMe(){}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &copy)
{
	*this = copy;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &merge)
{
	this->container = merge.container;
	return (*this);
}

static bool checkNumbers(char *numbers[], const size_t &argc)
{
	for (size_t i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < static_cast<std::string>(numbers[i]).length(); j++)
		{
			if (isdigit(numbers[i][j]) == false && numbers[i][j] != ' ')
				return false;
		}
	}
	return true;
}

template <typename T>
void PmergeMe<T>::getNumbers(char *numbers[], const size_t &argc)
{
	if (checkNumbers(numbers, argc) == false)
	{
		throw std::invalid_argument("Error");
		return ;
	}
	for (size_t i = 1; i < argc; i++)
	{
		std::stringstream ss(numbers[i]);
		std::string item;
		while (getline(ss, item, ' '))
			this->container.push_back(std::stoi(item));
	}
}

template <typename T>
void PmergeMe<T>::printNumbers(const std::string &prefix) const
{
	std::cout << prefix;
	typename T::const_iterator it = this->container.begin();
	typename T::const_iterator ite = this->container.end();
	while (it != ite)
	{
		std::cout <<  " " << *it;
		it++;
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::insertion(T &container, size_t index, const size_t limit)
{
	typename T::const_iterator it_main;
	while (index < limit)
	{
		it_main = this->container.begin();
		std::advance(it_main, index);
		container.push_back(*it_main);
		index++;
	}
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	int temp;
	while (it != ite)
	{
		if (std::next(it) != container.end() && *it > *std::next(it))
		{
			temp = *it;
			*it = *std::next(it);
			*std::next(it) = temp;
			while (it != container.begin() && *it < *std::prev(it))
			{
				temp = *it;
				*it = *std::prev(it);
				*std::prev(it) = temp;
				it--;
			}
		}
		else
			it++;
	}
}

template <typename T>
std::string PmergeMe<T>::mergeInsertion(const std::string &name)
{
	std::clock_t start = std::clock();
	T half1;
	T half2;
	size_t size = this->container.size();
	this->insertion(half1, 0, size / 2);
	this->insertion(half2, size / 2, size);
	this->container.clear();
	typename T::iterator it1 = half1.begin();
	typename T::iterator ite1 = half1.end();
	typename T::iterator it2 = half2.begin();
	typename T::iterator ite2 = half2.end();
	while (it1 != ite1 || it2 != ite2)
	{
		if (it1 != ite1 && it2 != ite2)
		{
			if (*it1 < *it2)
			{
				this->container.push_back(*it1);
				it1++;
			}
			else
			{
				this->container.push_back(*it2);
				it2++;
			}
			continue;
		}
		if (it1 != ite1)
		{
			this->container.push_back(*it1);
			it1++;
		}
		if (it2 != ite2)
		{
			this->container.push_back(*it2);
			it2++;
		}
	}
	std::clock_t end = std::clock();
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::string out = "Time to process a range of " + std::to_string(size) + " elements with " \
	+ name + " : " + std::to_string(elapsedTime) + " us";
	return out;
}