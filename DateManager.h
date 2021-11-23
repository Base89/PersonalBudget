#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
    static const int AMOUNT_MONTH_DAYS[][13];

    static bool isYearLeap(int year);
    string convertIntDateToDateWithDashes(int intDate);
    static string convertDateToDoubleDigit(string inputDate);
    static bool isDateDigits(string enteredDate);
    static string validateYear();
    static string validateMonth();
    static string validateDay(string enteredYear, string enteredMonth);
    static string typeDate();
public:

    static string getCurrentDate();
    static string getUserDate();
    static int convertDateSeparatedDashesToInt(string dateSeparatedDashes);
};

#endif
