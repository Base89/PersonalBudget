#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "FinanceManager.h"

using namespace std;

class IncomeManager : public FinanceManager
{
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
};

#endif
