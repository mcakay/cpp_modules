#include "PmergeMe.hpp"
#include <list>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	try {
		PmergeMe<std::vector<int> > vector;
		PmergeMe<std::list<int> > list;
		vector.getNumbers(argv, argc);
		list.getNumbers(argv, argc);
		vector.printNumbers("Before: ");
		std::string outVector = vector.mergeInsertion("std::vector");
		std::string outList = list.mergeInsertion("std::list");
		list.printNumbers("After:  ");
		std::cout << outVector << std::endl;
		std::cout << outList << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}