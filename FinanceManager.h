#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

#include "AuxiliaryMethods.h"

using namespace std;

class FinanceManager
{
    int getLoggedInUserId();
    bool isValidSeparated(string amount);
    bool isGreaterThanZero(string amount);
    bool isAmountDigit(string amount);
    string saveTwoDecimalPlaces(string amount);

public:
    double validateAmount();
    double setPrecisionToTwoDecimalPlaces(double doubleNumber);
};

#endif
