#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "Undefined AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}
