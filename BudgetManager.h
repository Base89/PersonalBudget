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
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

    void displayCurrentMonthBalanceHeader();
    void displayPreviousMonthBalanceHeader();
    void displaySelectedPeriodBalanceHeader();

public:
    BudgetManager(string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId)
        : FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomeManager = NULL;
        expenseManager = NULL;
        incomeManager = new IncomeManager(FILE_NAME_WITH_INCOMES, LOGGED_IN_USER_ID);
        expenseManager = new ExpenseManager(FILE_NAME_WITH_EXPENSES, LOGGED_IN_USER_ID);
    };
    ~BudgetManager()
    {
        delete incomeManager;
        delete expenseManager;
        incomeManager = NULL;
        expenseManager = NULL;
    };

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
};

#endif
