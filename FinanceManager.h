#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class FinanceManager
{
    int getLoggedInUserId();
    bool isValidSeparated(string amount);
    bool isGreaterThanZero(string amount);
    bool isAmountDigit(string amount);
    string saveTwoDecimalPlaces(string amount);
    char selectOptionFromDateMenu();

protected:
    int selectDate();
    double validateAmount();
    double setPrecisionToTwoDecimalPlaces(double doubleNumber);
};

#endif
