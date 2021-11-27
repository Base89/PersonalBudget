#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>

#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

using namespace std;

class BudgetManager
{
    const int LOGGED_IN_USER_ID;
    IncomeManager incomeManager;
    ExpenseManager expenseManager;

    void displayCurrentMonthBalanceHeader();
    void displayPreviousMonthBalanceHeader();
    void displaySelectedPeriodBalanceHeader();

public:
    BudgetManager(string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId)
        : incomeManager(fileNameWithIncomes, loggedInUserId), expenseManager(fileNameWithExpenses, loggedInUserId), LOGGED_IN_USER_ID(loggedInUserId)
    {};

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
};

#endif
