#include "FinanceManager.h"

int FinanceManager::getLoggedInUserId()
{

}

string FinanceManager::validateAmount()
{
    bool validAmount = 0;
    string strAmount = "";

    while (validAmount == 0)
    {
        strAmount = AuxiliaryMethods::enterInputData();

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
            strAmount = saveTwoDecimalPlaces(strAmount);

    }
    return strAmount;
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
