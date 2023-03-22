#ifndef DATE_HPP
# define DATE_HPP

#include <iostream>

typedef struct s_date
{
	int year;
	int month;
	int day;
	bool operator<(const s_date &date) const;
    bool operator>(const s_date &date) const;
    bool operator<=(const s_date &date) const;
    bool operator>=(const s_date &date) const;
	bool operator==(const s_date &date) const;
}	t_date;

#endif