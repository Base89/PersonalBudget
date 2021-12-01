#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
    static const int AMOUNT_MONTH_DAYS[][13];
    static const int DATE_DIGITS = 8;
    static const int START_OF_DAY_SCOPE = 6;

    static bool isYearLeap(int year);
    static string convertDateToDoubleDigit(string inputDate);
    static bool isDateDigits(string enteredDate);
    static string validateYear();
    static string validateMonth();
    static string validateDay(string enteredYear, string enteredMonth);
    static string typeDate();
    static string getYearFromDate(string selectedDate);
    static string getMonthFromDate(string selectedDate);
    static string getDayFromDate(string selectedDate);
    static string getPreviousMonth(int year, int month);
    static int getDaysSelectedMonth(string selectedDate);
    static char selectOptionFromDateMenu();
public:

    static string getCurrentDate();
    static string getUserDate();
    static int selectDate();
    static string convertIntDateToDateWithDashes(int intDate);
    static int convertDateSeparatedDashesToInt(string dateWithDashes);
    static string getFirstDayOfMonth(string currentDateWithDashes);
    static string getFirstDayOfPreviousMonth();
    static string getLastDayOfMonth(string selectedDate);
};

#endif
