#include "Point.hpp"
#include <cmath>

Point::Point() : x(0), y(0) {}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point::Point(Fixed x, Fixed y) : x(x), y(y) {}

Point::~Point() {}

Point &Point::operator=(const Point &copy)
{
	x = copy.x;
	y = copy.y;
	return *this;
}

Fixed Point::get_x() const
{
	return x;
}

Fixed Point::get_y() const
{
	return y;
}
