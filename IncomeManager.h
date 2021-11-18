#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "FinanceManager.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomeManager : public FinanceManager
{
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income getNewIncomeData();
    void sortIncomesFromEldest();
    double sumIncomes();
    void displayIncomes();
    void displayIncomesSum();
    void displayAmountOfIncomes();
    void searchIncomesBySelectedPeriod();

public:
    IncomeManager() {}

    void addIncome();
    void displayIncomeBalance();
};

#endif
