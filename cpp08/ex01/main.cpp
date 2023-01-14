#include "Span.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./span [mode]" << std::endl;
		return 1;
	}
	std::string mode = argv[1];
	if (mode == "main")
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	else if (mode == "test")
	{
		Span sp = Span(10000);
		sp.addRandomNumbers(10000);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	else
	{
		std::cout << "Mode must equal to (main) or (number)" << std::endl;
		return 1;
	}
	return 0;
}