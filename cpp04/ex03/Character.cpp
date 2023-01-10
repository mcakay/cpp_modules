#include "Character.hpp"

Character::Character()
{
	this->occupied = 0;
	this->name = "Default";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

Character::Character(Character const &other)
{
	*this = other;
}

Character::Character(std::string const &name) : name(name)
{
	this->occupied = 0;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character &Character::operator=(Character const &other)
{
	this->occupied = other.occupied;
	this->name = other.name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = other.inventory[i];
	return *this;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (this->occupied < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] == NULL)
				this->inventory[this->occupied] = m;
		}
		this->occupied++;
		std::cout << this->getName() + " equipped " << m->getType() << " at slot " << this->occupied << std::endl;
	}
	else
		std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 4)
	{
		this->inventory[idx] = NULL;
		this->occupied--;
		std::cout << this->getName() + " unequipped " << this->inventory[idx]->getType() << " at slot " << idx + 1 << std::endl;
	}
	else
		std::cout << "Invalid slot" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		this->inventory[idx]->use(target);
	}
	else
		std::cout << "Invalid slot" << std::endl;
}
