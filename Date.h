#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
    string day;
    string month;
    string year;
    int date;

public:

    string getDay();
    string getMonth();
    string getYear();
    int getDate();

    void setDay(string newDay);
    void setMonth(string newMonth);
    void setYear(string newYear);
    void setDate(int newDate);
};


#endif
