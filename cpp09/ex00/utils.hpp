#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <sstream>
#include "date.hpp"

namespace utils
{
	void error(const std::string &err, const int &code);
	bool parse(const std::string &input, const char &delimeter, std::pair<t_date, float> &element);
}

#endif