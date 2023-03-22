#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange()
{
	this->data.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &exchange)
{
	this->data.clear();
	std::map<t_date, float>::const_iterator it = exchange.data.begin();
	std::map<t_date, float>::const_iterator ite = exchange.data.end();
	while (it != ite)
	{
		this->data.insert(*it);
		it++;
	}
	return (*this);
}

void BitcoinExchange::readData(const std::string &database)
{
	std::ifstream db(database);
	if (db.is_open() == true)
	{
		std::string line;
		bool start = false;
		while (getline(db, line))
		{
			if (start == false && line == "date,exchange_rate")
			{
				start = true;
				continue;
			}
			std::pair<t_date, float> element;
			utils::parse(line, ',', element);
			this->data.insert(element);
		}
	}
	else
		utils::error(database + " could not open file.", 2);
}

void BitcoinExchange::getExchange(const std::string &filename) const
{
	std::ifstream input(filename);
	if (input.is_open() == true)
	{
		std::string line;
		bool start = false;
		while (getline(input, line))
		{
			if (start == false && line == "date | value")
			{
				start = true;
				continue;
			}
			std::pair<t_date, float> element;
			if (utils::parse(line, '|', element) == false)
				continue ;
			std::map<t_date, float>::const_iterator it = this->data.find(element.first);
			if (it != this->data.end())
				std::cout << line.substr(0, line.find("|")) << "=> " << element.second << " = " << element.second * it->second << std::endl;
			else
			{
				std::map<t_date, float>::const_iterator it = this->data.lower_bound(element.first);
				if (it != data.begin())
					it--;
				std::cout << line.substr(0, line.find("|")) << "=> " << element.second << " = " << element.second * it->second << std::endl;
			}
		}
	}
	else
		utils::error(filename + " could not open file.", 3);
}
