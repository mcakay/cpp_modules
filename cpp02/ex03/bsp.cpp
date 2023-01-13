#include "Point.hpp"

Fixed calculateTriangleArea(Point a, Point b, Point c)
{
	float result = a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat());
	result += b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat());
	result += c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat());
	result = fabs(result) / 2;
	return Fixed(result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed t = calculateTriangleArea(a, b, c);
	Fixed p1 = calculateTriangleArea(point, b, c);
	Fixed p2 = calculateTriangleArea(a, point, c);
	Fixed p3 = calculateTriangleArea(a, b, point);
	return (t == p1 + p2 + p3);
}