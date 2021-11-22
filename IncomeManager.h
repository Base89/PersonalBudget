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
    vector <Income> sortIncomesFromEldest(vector <Income> incomes);
    double sumIncomes();
    void displayIncomes();
    void displayIncomesSum();
    void displayAmountOfIncomes();
    vector <Income> searchIncomesBySelectedPeriod(int startingDate, int closingDate);

public:
    IncomeManager(string fileNameWithIncomes) : fileWithIncomes(fileNameWithIncomes) {}

    void addIncome();
    void displayIncomeBalance();
};

#endif
