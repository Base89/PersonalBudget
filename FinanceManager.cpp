#include "FinanceManager.h"

int FinanceManager::getLoggedInUserId()
{

}

double FinanceManager::validateAmount()
{
    bool validAmount = 0;
    string strAmount = "";

    while (validAmount == 0)
    {
        strAmount = AuxiliaryMethods::loadInputData();

        if (!isValidSeparated(strAmount))
        {
            cout << "Entered amount is incorrect. Type amount with one float separator." << endl << "Try again : ";
            validAmount = 0;
        }

        if (!isGreaterThanZero(strAmount))
        {
            cout << "Entered amount is incorrect. Type amount greater than zero." << endl << "Try again : ";
            validAmount = 0;
        }

        if (!isAmountDigit(strAmount))
        {
            cout << "Entered amount is incorrect. Type amount in digits." << endl << "Try again : ";
            validAmount = 0;
        }
        else
            strAmount = AuxiliaryMethods::changeCommaForDot(saveTwoDecimalPlaces(strAmount));
    }
    return AuxiliaryMethods::convertStringToDouble(strAmount);
}

bool FinanceManager::isValidSeparated(string amount)
{
    const string COMMA = ",";
    const string DOT = ".";
    int position = 0;

    position = amount.find(COMMA);
    if (position == string::npos)
    {
        position = 0;
        position = amount.find(DOT);
        if (position == string::npos)
            return 1;
        else
        {
            position = amount.find(DOT, position + 1);
            if (position == string::npos)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        position = amount.find(COMMA, position + 1);
        if (position == string::npos)
        {
            position = 0;
            position = amount.find(DOT);
            if (position == string::npos)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
}

bool FinanceManager::isGreaterThanZero(string amount)
{
    double doubleAmount = 0;
    amount = AuxiliaryMethods::changeCommaForDot(amount);
    doubleAmount = AuxiliaryMethods::convertStringToDouble(amount);

    if (doubleAmount <= 0)
        return 0;

    return 1;
}

bool FinanceManager::isAmountDigit(string amount)
{
    for (int i = 0; i < amount.size(); i++)
    {
        if (!isdigit(amount[i]) && !(amount[i] == ',' || amount[i] == '.'))
            return 0;
    }
    return 1;
}

string FinanceManager::saveTwoDecimalPlaces(string amount)
{
    const string COMMA = ",";
    const string DOT = ".";
    int position = 0;

    position = amount.find(COMMA);
    if (position == string::npos)
    {
        position = 0;
        position = amount.find(DOT);
        return amount.substr (0, position + 3);
    }
    else
        return amount.substr (0, position + 3);
}

int FinanceManager::selectDate()
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
            date = DateManager::convertDateSeparatedDashesToInt(DateManager::getCurrentDate());
            cout << "Today's date downloaded" << endl;
            dateMenu = 1;
        }
        else if (choice == '2')
        {
            cout << "Please, enter your date:";
            date = DateManager::convertDateSeparatedDashesToInt(DateManager::getUserDate());
            dateMenu = 1;
        }
        else if (choice == '9')
        {
            cout << endl << "Back to User Menu" << endl << endl;
            break;
        }
        else
        {
            cout << endl << "Incorrect choice! Try again." << endl << endl;
            dateMenu = 0;
        }
    }
    return date;
}

char FinanceManager::selectOptionFromDateMenu()
{
    cout << "1 - Today's date" << endl;
    cout << "2 - Other date" << endl;
    cout << "9 - Back " << endl;
    cout << endl << "Your choice: ";

    return AuxiliaryMethods::loadChar();
}

double FinanceManager::setPrecisionToTwoDecimalPlaces(double doubleNumber)
{
    int intNumber = doubleNumber * 100;

    return (intNumber * 0.01);
}
