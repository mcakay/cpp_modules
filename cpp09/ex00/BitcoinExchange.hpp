#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <fstream>
#include "utils.hpp"

class BitcoinExchange
{
	private:
		std::map<t_date, float> data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &exchange);
		void readData(const std::string &database);
		void getExchange(const std::string &filename) const;
};

#endif