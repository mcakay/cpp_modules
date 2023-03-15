#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	std::map<t_date, float>::const_iterator it = copy.data.begin();
	std::map<t_date, float>::const_iterator ite = copy.data.end();
	this->data.clear();
	while (it != ite)
	{
		this->data.insert(std::pair<t_date, float>(it->first, it->second));
		it++;
	}
	return (*this);
}

bool t_date::operator<(const s_date& rhs) const
{
    if (year != rhs.year)
        return year < rhs.year;
    if (month != rhs.month)
        return month < rhs.month;
    return day < rhs.day;
}

bool t_date::operator>(const s_date& rhs) const
{
    return rhs < *this;
}

bool t_date::operator<=(const s_date& rhs) const
{
    return !(rhs < *this);
}

bool t_date::operator>=(const s_date& rhs) const
{
    return !(*this < rhs);
}


void BitcoinExchange::error(const std::string &err, const unsigned int &exitCode)
{
	std::cerr << "Error: " + err << std::endl;
	if (exitCode != 0)
	{
		std::cerr << "Exiting with code " << exitCode << std::endl;
		exit(exitCode);
	}
}

void BitcoinExchange::readData(const std::string &filename)
{
	std::ifstream database(filename);
	if (database.is_open() == true)
	{
		std::string line;
		while (getline(database, line))
		{
			this->data.insert(std::pair<t_date, float>(, ));
		}
		database.close();
	}
	else
		this->error("File is not opened", 2);
}
