#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		~Point();
		Point(const Point &copy);
		Point(Fixed x, Fixed y);
		Point &operator=(const Point &copy);
		Fixed get_x() const;
		Fixed get_y() const;
		Fixed distanceTo(const Point &point) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif