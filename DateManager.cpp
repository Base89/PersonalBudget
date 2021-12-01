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
        if (!isdigit(enteredDate[charPosition]))
        {
            cout << "Entered date is not number. Type the date in digits." << endl << "Try again : ";
            return false;
        }
    }
    return true;
}

string DateManager::validateYear()
{
    const int BORDER_YEAR = 2000;
    bool validYear = 0;
    int intYear = 0;

    while (validYear == 0)
    {
        intYear = AuxiliaryMethods::convertStringToInt(typeDate());

        if ((intYear < BORDER_YEAR))
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
    const int AMOUNT_MONTHS = 12;
    bool validMonth = 0;
    int intMonth = 0;

    while (validMonth == 0)
    {
        intMonth = AuxiliaryMethods::convertStringToInt(typeDate());

        if ((intMonth < 1) || (intMonth > AMOUNT_MONTHS))
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
        getline(cin, inputDate);
        digitalDate = isDateDigits(inputDate);
    }
    return inputDate;
}

string DateManager::getYearFromDate(string selectedDate)
{
    const int YEAR_DIGITS = 4;
    string year = "";

    for (int i = 0; i < DATE_DIGITS; i++)
    {
        if (i < YEAR_DIGITS)
        {
            year += selectedDate[i];
        }
    }
    return year;
}

string DateManager::getMonthFromDate(string selectedDate)
{
    const int START_OF_MONTH_SCOPE = 4;
    string month = "";

    for (int i = 0; i < DATE_DIGITS; i++)
    {
        if (i >= START_OF_MONTH_SCOPE && i <= START_OF_MONTH_SCOPE + 1)
        {
            month += selectedDate[i];
        }
    }
    return month;
}

string DateManager::getDayFromDate(string selectedDate)
{
    string day = "";

    for (int i = 0; i < DATE_DIGITS; i++)
    {
        if (i >= START_OF_DAY_SCOPE)
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

int DateManager::selectDate()
{
    bool dateMenu = 0;
    char choice;
    int date = 0;

    while (dateMenu == 0)
    {
        cout << ">> Select date <<" << endl << endl;
        choice = selectOptionFromDateMenu();

        if (choice == '1')
        {
            date = convertDateSeparatedDashesToInt(getCurrentDate());
            cout << "Today's date downloaded" << endl;
            dateMenu = 1;
        }
        else if (choice == '2')
        {
            cout << "Please, enter your date:" << endl;
            date = convertDateSeparatedDashesToInt(getUserDate());
            dateMenu = 1;
        }
        else
        {
            cout << endl << "Incorrect choice! Try again." << endl << endl;
            dateMenu = 0;
        }
    }
    return date;
}

char DateManager::selectOptionFromDateMenu()
{
    cout << "1 - Today's date" << endl;
    cout << "2 - Other date" << endl;
    cout << endl << "Your choice: ";

    return AuxiliaryMethods::loadChar();
}

int DateManager::convertDateSeparatedDashesToInt(string dateWithDashes)
{
    string dateWithoutDashes = "";

    for (int i = 0; i < dateWithDashes.length(); i++)
    {
        if (isdigit(dateWithDashes[i]))
            dateWithoutDashes += dateWithDashes[i];
    }
    return AuxiliaryMethods::convertStringToInt(dateWithoutDashes);
}

string DateManager::getFirstDayOfMonth(string currentDateWithDashes)
{
    string currentDate = AuxiliaryMethods::convertIntToString(convertDateSeparatedDashesToInt(currentDateWithDashes));

    for (int i = 0; i < DATE_DIGITS; i++)
    {
        if (i == START_OF_DAY_SCOPE)
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
    const string FIRST_DAY_MONTH = "01";
    const int JANUARY = 1;
    const int DECEMBER = 12;

    if (month == JANUARY)
    {
        month = DECEMBER;
        year--;
    }
    else
        month--;

    return AuxiliaryMethods::convertIntToString(year) + convertDateToDoubleDigit(AuxiliaryMethods::convertIntToString(month)) + FIRST_DAY_MONTH;
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
