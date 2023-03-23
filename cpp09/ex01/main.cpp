#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	RPN rpn;
	try
	{
		rpn.getResult(argv[1]);
	}
	catch(const std::invalid_argument &e)
	{
		std::cout << "Error" << std::endl;
	}
	return (0);
}