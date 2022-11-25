#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "Debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Error" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelIndex = 0;
	while (levelIndex < 4 && level != levels[levelIndex])
		levelIndex++;
	switch (levelIndex)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "Probably complaining about insignificant problems" << std::endl;
			break;
	}
}