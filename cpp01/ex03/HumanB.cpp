#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (weapon != NULL)
		std::cout << this->name << " attacks with his " << weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with his fists" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}