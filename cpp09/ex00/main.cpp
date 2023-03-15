#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange btc;
	(void)argv;
	if (argc != 2)
		btc.error("Invalid number of arguments", 1);
	btc.readData("data.csv");
	return (0);
}