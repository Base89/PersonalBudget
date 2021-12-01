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
    bool isValidSeparated(string amount);
    bool isGreaterThanZero(string amount);
    bool isAmountDigit(string amount);

protected:
    int selectDate();
    double validateAmount();
};

#endif
