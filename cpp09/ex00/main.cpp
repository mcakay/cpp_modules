#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		utils::error("could not open file.", 1);
	BitcoinExchange btc;
	btc.readData("data.csv");
	btc.getExchange(argv[1]);
	return 0;
}