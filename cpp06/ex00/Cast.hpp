#ifndef CAST_HPP
# define CAST_HPP

#include "Error.hpp"

class Cast
{
	public:
		Cast();
		~Cast();
		Cast(Cast const &src);
		Cast &operator=(Cast const &other);
		void castChar(std::string input, Error err);
		void castInt(std::string input, Error err);
		void castFloat(std::string input, Error err);
		void castDouble(std::string input, Error err);
};

#endif