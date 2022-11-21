#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	std::cout << name << " is born!" << std::endl;
	this->name = name;
}

Zombie::Zombie(void)
{
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
