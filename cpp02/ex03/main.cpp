#include "Fixed.hpp"
#include "Point.hpp"
#include <fstream>

int main(int argc, char **argv) 
{
	if (argc != 9)
	{
		std::cout << "Usage: ./bsp ax ay bx by cx cy px py" << std::endl;
		return (1);
	}
	Point a = Point(Fixed((const float)atof(argv[1])), Fixed((const float)atof(argv[2])));
	Point b = Point(Fixed((const float)atof(argv[3])), Fixed((const float)atof(argv[4])));
	Point c = Point(Fixed((const float)atof(argv[5])), Fixed((const float)atof(argv[6])));
	Point point = Point(Fixed((const float)atof(argv[7])), Fixed((const float)atof(argv[8])));
	std::cout << "Point is ";
	if (!bsp(a, b, c, point))
		std::cout << "not ";
	std::cout << "inside the triangle" << std::endl;
	return (0);
}