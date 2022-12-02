#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int intVal)
{
	value = intVal * 256;
}

Fixed::Fixed(const float floatVal)
{
	value = roundf(floatVal * 256);
}

Fixed &Fixed::operator=(const Fixed &number)
{
	this->value = number.value;
	return (*this);
}

int Fixed::toInt() const
{
	return (value / 256);
}

float Fixed::toFloat() const
{
	return (float(value) / 256);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

bool Fixed::operator>(const Fixed &number)
{
	return (this->value > number.value);
}

bool Fixed::operator<(const Fixed &number)
{
	return (this->value < number.value);
}

bool Fixed::operator>=(const Fixed &number)
{
	return (this->value >= number.value);
}

bool Fixed::operator<=(const Fixed &number)
{
	return (this->value <= number.value);
}

bool Fixed::operator==(const Fixed &number)
{
	return (this->value == number.value);
}

bool Fixed::operator!=(const Fixed &number)
{
	return (this->value != number.value);
}

Fixed Fixed::operator+(const Fixed &number)
{
	Fixed rtn(this->toFloat() + number.toFloat());
	return (rtn);
}

Fixed Fixed::operator-(const Fixed &number)
{
	Fixed rtn(this->toFloat() - number.toFloat());
	return (rtn);
}

Fixed Fixed::operator*(const Fixed &number)
{
	Fixed rtn(this->toFloat() * number.toFloat());
	return (rtn);
}

Fixed Fixed::operator/(const Fixed &number)
{
	Fixed rtn(this->toFloat() / number.toFloat());
	return (rtn);
}

Fixed Fixed::operator++(int)
{
	Fixed rtn = *this;
	this->value++;
	return (rtn);
}

Fixed &Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed rtn = *this;
	this->value--;
	return (rtn);
}

Fixed &Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.value < f2.value)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.value > f2.value)
		return (f1);
	return (f2);
}
