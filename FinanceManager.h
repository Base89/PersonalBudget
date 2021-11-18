#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <string>
#include <cctype>

#include "AuxiliaryMethods.h"

using namespace std;

class FinanceManager
{
    int getLoggedInUserId();
    bool isValidSeparated(string amount);
    bool isGreaterThanZero(string amount);
    bool isAmountDigit(string amount);
    string saveTwoDecimalPlaces(string amount);
    void getDatePeriod();

public:
    string validateAmount();
};

#endif
