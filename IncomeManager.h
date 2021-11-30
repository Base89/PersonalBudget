#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

#include "Income.h"
#include "FinanceManager.h"
#include "FileWithIncomes.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeManager : public FinanceManager
{
    const int LOGGED_IN_USER_ID;
    double sumSelectedIncomes;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income getNewIncomeData();
    vector <Income> sortIncomesFromEldest(vector <Income> selectedIncomes);
    double sumIncomes(vector <Income> selectedIncomes);
    void displayIncome(Income income);
    void displayAllIncomes(vector <Income> selectedIncomes);
    void displayIncomesSum(vector <Income> selectedIncomes);
    void displayAmountOfIncomes(int amountIncomes);
    vector <Income> searchIncomesBySelectedPeriod(int startingDate, int closingDate);

    void setSumSelectedIncomes(double newSumSelectedIncomes);

public:
    IncomeManager(string fileNameWithIncomes, int loggedInUserId) : fileWithIncomes(fileNameWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void displayIncomeBalanceOfCurrentMonth();
    void displayIncomeBalanceOfPreviousMonth();
    void displayIncomeBalanceOfSelectedPeriod(int firstDate, int lastDate);

    double getSumSelectedIncomes();
};

#endif
