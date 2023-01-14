#include "easyfind.hpp"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Usage: ./easyfind [number1] [number2]" << std::endl;
		return 1;
	}
	std::vector<int> v(1, 10);

	v.push_back(2);
	v.push_back(7);
	try {
		std::cout << *(easyfind(v, std::stoi(argv[1]))) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Can't find " << argv[1] << std::endl;
	}
	try {
		std::cout << *(easyfind(v, std::stoi(argv[2]))) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Can't find " << argv[2] << std::endl;
	}
	return 0;
}