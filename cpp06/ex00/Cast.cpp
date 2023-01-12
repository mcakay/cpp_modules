#include "Cast.hpp"

Cast::Cast()
{
}

Cast::~Cast()
{}

Cast::Cast(Cast const &src)
{
	*this = src;
}

Cast &Cast::operator=(Cast const &other)
{
	(void)other;
	return *this;
}

void Cast::castChar(std::string input, Error err)
{
	char c;

	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (input.length() == 1)
	{
		c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		return ;
	}
	int i = err.checkRange("char", input);
	if (i != -1 && (i < 32 || i > 127))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	if (i != -1)
	{
		c = static_cast<char>(i);
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

void Cast::castInt(std::string input, Error err)
{
	int i;

	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (input.length() == 1)
	{
		if (isdigit(input[0]) == 0)
			i = static_cast<int>(input[0]);
		else
			i = std::stoi(input);
		std::cout << "int: " << i << std::endl;
		return ;
	}
	i = err.checkRange("int", input);
	if (i != -1)
		std::cout << "int: " <<  std::stoi(input) << std::endl;
}

void Cast::castFloat(std::string input, Error err)
{
	float f;

	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
	{
		std::cout << "float: " << input << "f" << std::endl;
		return ;
	}
	if (input.length() == 1)
	{
		if (isdigit(input[0]) == 0)
			f = static_cast<float>(input[0]);
		else
			f = std::stof(input);
		std::cout << "float: " << f << "f" << std::endl;
		return ;
	}
	int i = err.checkRange("float", input);
	if (i != -1)
	{
		f = std::stof(input);
		if (f - static_cast<int>(f) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
}

void Cast::castDouble(std::string input, Error err)
{
	double d;

	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
	{
		std::cout << "double: " << input << std::endl;
		return ;
	}
	if (input.length() == 1)
	{
		if (isdigit(input[0]) == 0)
			d = static_cast<double>(input[0]);
		else
			d = std::stod(input);
		std::cout << "double: " << d << std::endl;
		return ;
	}
	int i = err.checkRange("double", input);
	if (i != -1)
	{
		d = std::stod(input);
		if (d - static_cast<int>(d) == 0)
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}	
}