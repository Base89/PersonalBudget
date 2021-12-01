#include "FinanceManager.h"

double FinanceManager::validateAmount()
{
    bool validAmount = 0;
    string strAmount = "";

    while (validAmount == 0)
    {
        strAmount = AuxiliaryMethods::loadInputData();

        if (!isValidSeparated(strAmount))
        {
            cout << "Entered amount is incorrect. Type amount with one float separator." << endl << "Try again: ";
            validAmount = 0;
        }
        else if (!isGreaterThanZero(strAmount))
        {
            cout << "Entered amount is incorrect. Type amount greater than zero." << endl << "Try again: ";
            validAmount = 0;
        }
        else if (!isAmountDigit(strAmount))
        {
            cout << "Entered amount is incorrect. Type amount in digits." << endl << "Try again: ";
            validAmount = 0;
        }
        else
        {
            strAmount = AuxiliaryMethods::changeCommaForDot(strAmount);
            validAmount = 1;
        }
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
            return (position == string::npos) ? 1 : 0;
        }
    }
    else
    {
        position = amount.find(COMMA, position + 1);
        if (position == string::npos)
        {
            position = 0;
            position = amount.find(DOT);
            return (position == string::npos) ? 1 : 0;
        }
        else
            return 0;
    }
}

bool FinanceManager::isGreaterThanZero(string amount)
{
    amount = AuxiliaryMethods::changeCommaForDot(amount);
    return (AuxiliaryMethods::convertStringToDouble(amount) <= 0) ? 0 : 1;
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

int FinanceManager::selectDate()
{
    return DateManager::selectDate();
}
