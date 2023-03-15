#ifndef BITCOIN_EXCHANGE
# define BITCOIN_EXCHANGE

#include <fstream>
#include <iostream>
#include <map>

typedef struct s_date
{
    int day;
    int month;
    int year;
	bool operator<(const s_date& rhs) const;
    bool operator>(const s_date& rhs) const;
    bool operator<=(const s_date& rhs) const;
    bool operator>=(const s_date& rhs) const;
} t_date;

typedef std::map<t_date, float> t_data;

class BitcoinExchange
{
	private:
		t_data data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &btc);
		void error(const std::string &err, const unsigned int &exitCode);
		void readData(const std::string &filename);
};

#endif