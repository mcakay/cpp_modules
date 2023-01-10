#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "Undefiend";
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	this->type = other.type;
	std::cout << "AAnimal assignation operator called" << std::endl;
	return (*this);
}

void AAnimal::makeSound() const
{
	std::cout << "Undefined AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}
