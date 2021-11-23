#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
    static const int AMOUNT_MONTH_DAYS[][13];

    bool isYearLeap(int year);
    int getAmountDaysOfMonth(int month, int year);
    int getAmountDaysOfYear(int day, int month, int year);
    int convertDateSeparatedDashesToInt(string dateSeparatedDashes);
    string convertIntDateToDateWithDashes(int intDate);
    string convertDateToDoubleDigit(string inputDate);
    bool isDateDigits(string enteredDate);
    string validateYear();
    string validateMonth();
    string validateDay(string enteredYear, string enteredMonth);
    string typeDate();
public:

    string getCurrentDate();
    string getUserDate();
};

#endif
