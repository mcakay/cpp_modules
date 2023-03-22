#include "date.hpp"


bool t_date::operator<(const s_date &date) const
{
    if (year != date.year)
        return year < date.year;
    if (month != date.month)
        return month < date.month;
    return day < date.day;
}

bool t_date::operator>(const s_date &date) const
{
    return date < *this;
}

bool t_date::operator<=(const s_date &date) const
{
    return !(date < *this);
}

bool t_date::operator>=(const s_date &date) const
{
    return !(*this < date);
}

bool t_date::operator==(const s_date &date) const
{
    if (this->year == date.year && this->month == date.month && this->day == date.day)
		return true;
	return false;
}
