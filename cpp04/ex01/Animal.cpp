#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Undefiend";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	this->type = other.type;
	std::cout << "Animal assignation operator called" << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Undefined animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
