#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int intVal)
{
	std::cout << "Int constructor called" << std::endl;
	value = intVal * pow(2, fractionalBits);
}

Fixed::Fixed(const float floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(floatVal * pow(2, fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &number)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->value = number.value;
	return (*this);
}

int Fixed::toInt() const
{
	return (value / pow(2, fractionalBits));
}

float Fixed::toFloat() const
{
	return (float(value) / pow(2, fractionalBits));
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}