#include "utils.hpp"

static bool checkFeb(const t_date &date)
{
	if (date.year % 100 == 0 && date.year % 400 != 0) 
		return false;
    if (date.year % 400 == 0 && date.year % 4000 == 0) 
		return false;
    if (date.year % 4 == 0)
		return true;
    return false; 
}

static bool checkValue(const float &value)
{
	if (value < 0)
	{
		utils::error("not a positive number.", 0);
		return false;
	}
	else if (value > 1000)
	{
		utils::error("too large a number.", 0);
		return false;
	}
	return true;
}

static bool checkDate(const t_date &date, const std::string &input)
{
	if (date.month < 0 || date.month > 12)
	{
		utils::error("bad input => " + input, 0);
		return false;
	}
	if (date.month == 2 && date.day > 28 + checkFeb(date))
	{
		utils::error("bad input => " + input, 0);
		return false;
	}
	else if (date.month <= 7 && date.day > 30 + (date.month % 2 == 1))
	{
		utils::error("bad input => " + input, 0);
		return false;
	}
	else if (date.month >= 8 && date.day > 30 + (date.month % 2 == 0))
	{
		utils::error("bad input => " + input, 0);
		return false;
	}
	if (date.year == 1582 && date.day > 4 && date.day < 15)
	{
		utils::error("bad input => " + input, 0);
		return false;
	}
	return true;
}

static bool parseDate(const std::string &date_str, const std::string &input, t_date &date)
{
	std::string item;
	std::stringstream ss(date_str);
	int index = 0;
	while (getline(ss, item, '-'))
	{
		try{
			if (index == 0)
				date.year = std::stoi(item);
			else if (index == 1)
				date.month = std::stoi(item);
			else if (index == 2)
				date.day = std::stoi(item);
		}
		catch (std::exception &e)
		{
			utils::error("bad input => " + input, 0);
			return false;
		}
		index++;
	}
	if (index != 3)
	{
		utils::error("bad input => " + input, 0);
		return false;
	}
	return true;
}

namespace utils
{
	void error(const std::string &err, const int &code)
	{
		std::cout << "Error: " + err << std::endl;
		if (code != 0)
			exit(code);
	}
	
	bool parse(const std::string &input, const char &delimeter, std::pair<t_date, float> &element)
	{
		t_date date;
		if (input.find(delimeter) == std::string::npos)
		{
			utils::error("bad input => " + input, 0);
			return false;
		}
		std::stringstream ss(input);
		std::string item;
		getline(ss, item, delimeter);
		if (parseDate(item, input, date) == false)
			return false;
		float value;
		getline(ss, item, delimeter);
		if (delimeter == '|')
		{
			try
			{
				value = std::stof(item);
			}
			catch(const std::exception& e)
			{
				utils::error("bad input => " + input, 0);
				return false;
			}
			if (checkDate(date, input) == false)
				return false;
			if (checkValue(value) == false)
				return false;
		}
		else
			value = std::stof(item);
		element = std::pair<t_date, float>(date, value);
		return true;
	}
}