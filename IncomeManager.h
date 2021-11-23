#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "FinanceManager.h"
#include "FileWithIncomes.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeManager : public FinanceManager
{
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income getNewIncomeData();
    vector <Income> sortIncomesFromEldest(vector <Income> incomes);
    double sumIncomes();
    void displayIncomes();
    void displayIncomesSum();
    void displayAmountOfIncomes();
    vector <Income> searchIncomesBySelectedPeriod(int startingDate, int closingDate);
    char selectOptionFromDateMenu();

public:
    IncomeManager(string fileNameWithIncomes, int loggedInUserId) : fileWithIncomes(fileNameWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void displayIncomeBalance();
};

#endif
