#include "DateManager.h"

const int DateManager::AMOUNT_MONTH_DAYS[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool DateManager::isYearLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

string DateManager::convertIntDateToDateWithDashes(int intDate)
{
    string strDate = AuxiliaryMethods::convertIntToString(intDate);

    return getYearFromDate(strDate) + '-' + getMonthFromDate(strDate) + '-' + getDayFromDate(strDate);
}

string DateManager::convertDateToDoubleDigit(string inputDate)
{
    char doubleDigit[3] = "00";

    if (inputDate.length() == 1)
        doubleDigit[1] = inputDate[0];
    else
        return inputDate;

    return doubleDigit;
}

bool DateManager::isDateDigits(string enteredDate)
{
    for (int charPosition = 0; charPosition < enteredDate.length(); charPosition++)
    {
        if (isdigit(enteredDate[charPosition]) == false)
        {
            cout << "Entered date is not number. Type the date in digits." << endl << "Try again : ";
            return false;
        }
    }
    return true;
}

string DateManager::validateYear()
{
    const int borderYear = 2000;
    bool validYear = 0;
    int intYear = 0;

    while (validYear == 0)
    {
        intYear = AuxiliaryMethods::convertStringToInt(typeDate());

        if ((intYear < borderYear))
        {
            cout << "Entered year is below the range. Type year above 1999." << endl << "Try again : ";
            validYear = 0;
        }
        else
            validYear = 1;
    }
    return AuxiliaryMethods::convertIntToString(intYear);
}

string DateManager::validateMonth()
{
    const int amountMonths = 12;
    bool validMonth = 0;
    int intMonth = 0;

    while (validMonth == 0)
    {
        intMonth = AuxiliaryMethods::convertStringToInt(typeDate());

        if ((intMonth < 1) || (intMonth > amountMonths))
        {
            cout << "Entered month is out of range. Type valid month number (1-12)." << endl << "Try again : ";
            validMonth = 0;
        }
        else
            validMonth = 1;
    }
    return AuxiliaryMethods::convertIntToString(intMonth);
}

string DateManager::validateDay(string enteredYear, string enteredMonth)
{
    int amountDaysInMonth = AMOUNT_MONTH_DAYS[isYearLeap(AuxiliaryMethods::convertStringToInt(enteredYear))][AuxiliaryMethods::convertStringToInt(enteredMonth)];
    bool validDay = 0;
    int intDay = 0;

    while (validDay == 0)
    {
        intDay = AuxiliaryMethods::convertStringToInt(typeDate());

        if ((intDay < 1) || (intDay > amountDaysInMonth))
        {
            cout << "Entered day is out of range. Type valid day of month." << endl << "Try again : ";
            validDay = 0;
        }
        else
            validDay = 1;
    }
    return AuxiliaryMethods::convertIntToString(intDay);
}

string DateManager::typeDate()
{
    string inputDate = "";
    bool digitalDate = 0;

    while (digitalDate == 0)
    {
        cin >> inputDate;
        digitalDate = isDateDigits(inputDate);
    }
    return inputDate;
}

string DateManager::getYearFromDate(string selectedDate)
{
    const int dateDigits = 8;
    string year = "";

    for (int i = 0; i < dateDigits; i++)
    {
        if (i <= 3)
        {
            year += selectedDate[i];
        }
    }
    return year;
}

string DateManager::getMonthFromDate(string selectedDate)
{
    const int dateDigits = 8;
    string month = "";

    for (int i = 0; i < dateDigits; i++)
    {
        if (i > 3 && i <= 5)
        {
            month += selectedDate[i];
        }
    }
    return month;
}

string DateManager::getDayFromDate(string selectedDate)
{
    const int dateDigits = 8;
    string day = "";

    for (int i = 0; i < dateDigits; i++)
    {
        if (i > 5)
        {
            day += selectedDate[i];
        }
    }
    return day;
}

string DateManager::getCurrentDate()
{
    time_t myDate;
    struct tm currentDate;
    time(&myDate);
    currentDate = *localtime(&myDate);

    char strDate[11];
    strftime(strDate, sizeof(strDate), "%Y-%m-%d", &currentDate);

    return strDate;
}

string DateManager::getUserDate()
{
    string year, month, day = "";

    cout << "Enter year : ";
    year = validateYear();

    cout << "Enter month : ";
    month = validateMonth();

    cout << "Enter day : ";
    day = validateDay(year, month);

    return year + '-' + convertDateToDoubleDigit(month) + '-' + convertDateToDoubleDigit(day);
}

int DateManager::convertDateSeparatedDashesToInt(string dateWithDashes)
{
    string dateWithoutDashes = "";

    for (int i = 0; i < dateWithDashes.length(); i++)
    {
        if (isdigit(dateWithDashes[i]) == true)
            dateWithoutDashes += dateWithDashes[i];
    }
    return AuxiliaryMethods::convertStringToInt(dateWithoutDashes);
}

string DateManager::getFirstDayOfMonth(string currentDateWithDashes)
{
    const int dateDigits = 8;
    string currentDate = AuxiliaryMethods::convertIntToString(convertDateSeparatedDashesToInt(currentDateWithDashes));

    for (int i = 0; i < dateDigits; i++)
    {
        if (i == 6)
        {
            currentDate[i] = '0';
            currentDate[i + 1] = '1';
        }
    }
    return currentDate;
}

string DateManager::getFirstDayOfPreviousMonth()
{
    string currentDate = AuxiliaryMethods::convertIntToString(convertDateSeparatedDashesToInt(getCurrentDate()));
    int year = AuxiliaryMethods::convertStringToInt(getYearFromDate(currentDate));
    int month = AuxiliaryMethods::convertStringToInt(getMonthFromDate(currentDate));

    return getPreviousMonth(year, month);
}

string DateManager::getPreviousMonth(int year, int month)
{
    string day = "01";

    if (month == 1)
    {
        month = 12;
        year--;
    }
    else
        month--;

    return AuxiliaryMethods::convertIntToString(year) + convertDateToDoubleDigit(AuxiliaryMethods::convertIntToString(month)) + day;
}

int DateManager::getDaysSelectedMonth(string selectedDate)
{

    return AMOUNT_MONTH_DAYS[isYearLeap(AuxiliaryMethods::convertStringToInt(getYearFromDate(selectedDate)))][AuxiliaryMethods::convertStringToInt(getMonthFromDate(selectedDate))];
}

string DateManager::getLastDayOfMonth(string selectedDate)
{
    string year = getYearFromDate(selectedDate);
    string month = getMonthFromDate(selectedDate);
    string day = AuxiliaryMethods::convertIntToString(getDaysSelectedMonth(selectedDate));

    return year + month + day;
}
