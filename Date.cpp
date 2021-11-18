#include "Date.h"

string Date::getDay()
{
    return day;
}

string Date::getMonth()
{
    return month;
}

string Date::getYear()
{
    return year;
}

int Date::getDate()
{
    return date;
}

void Date::setDay(string newDay)
{
    day = newDay;
}

void Date::setMonth(string newMonth)
{
    month = newMonth;
}

void Date::setYear(string newYear)
{
    year = newYear;
}

void Date::setDate(int newDate)
{
    const int BORDER_DATE = 20000000;
    if (newDate > BORDER_DATE)
    date = newDate;
}
