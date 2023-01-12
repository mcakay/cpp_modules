#include "Error.hpp"

Error::Error()
{
}

Error::~Error()
{

}

Error::Error(Error const &src)
{
	*this = src;
}

Error &Error::operator=(Error const &other)
{
	(void)other;
	return *this;
}

void Error::error(std::string message, int exitCode)
{
	std::cout << "Error: " + message << std::endl;
	std::cout << "Exit with code " << exitCode << std::endl;
	exit(exitCode);
}

void Error::checkArguments(int argc)
{
	if (argc != 2)
		error("Invalid number of arguments", 1);
}

void Error::checkCharacters(std::string input)
{
	if (input != "nan" 
	&& input != "nanf" 
	&& input != "+inf" 
	&& input != "-inf" 
	&& input != "+inff" 
	&& input != "-inff" 
	&& input.length() != 1)
	{
		if (input.find_first_not_of("0123456789.f") != std::string::npos)
			error("Input contains invalid chaacters", 3);
	}
}

void Error::checkDot(std::string input)
{
	if (input.find(".") != std::string::npos)
	{
		size_t dot = input.find(".");
		if (dot != input.find_last_of("."))
			error("Input contains multiple dots", 4);
		if (dot == 0)
			error("Input can't start with a dot", 5);
		if (dot == input.length() - 1)
			error("Input can't end with a dot", 6);
	}
}

void Error::checkf(std::string input)
{
	if (input.find("f") != std::string::npos)
	{
		size_t f = input.find("f");
		if (f == 0)
			error("Input can't start with a f", 7);
		if (f != input.find_last_of("f"))
			error("Input contains multiple f", 8);
		if (input[f - 1] == '.')
			error("Input can't contain a dot before f", 9);
	}
}

void Error::checkInput(std::string input)
{
	if (input.length() == 0)
		error("Input can't be empty", 2);
	checkPlusMinus(input);
	checkCharacters(input);
	checkDot(input);
	checkf(input);
}

void Error::checkPlusMinus(std::string &input)
{	
	if (input.find("+") != std::string::npos || input.find("-") != std::string::npos)
	{
		if ((input.find("-") != std::string::npos) && (input.find("+") != std::string::npos))
			error("Input contains multiple + and -", 10);
		if (input.find("-") != input.find_last_of("-") || input.find("+") != input.find_last_of("+"))
			error("Input can't contain a - in the middle", 11);
		input = input.substr(1, input.length());
	}
}

int Error::checkRange(std::string type, std::string input)
{
	int i = 0;
	if (type == "char" || type == "int")
	{
		try
		{
			i = std::stoi(input);
		}
		catch(const std::exception& e)
		{
			std::cout << type + ": impossible" << std::endl;
			return -1;
		}
	}
	else if (type == "float")
	{
		try
		{
			std::stof(input);
		}
		catch(const std::exception& e)
		{
			std::cout << type + ": impossible" << std::endl;
			return -1;
		}
	}
	else if (type == "double")
	{
		try
		{
			std::stod(input);
		}
		catch(const std::exception& e)
		{
			std::cout << type + ": impossible" << std::endl;
			return -1;
		}
	}
	return i;
}
