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
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

    void getCurrentDate();
    void enterAnotherDate();
    void getIncomeData();
    void getExpenseData();
    void getCurrentMonthPeriod();
    void getLastMonthPeriod();
    void getSelectedPeriod();
    void displayIncomeBalance();
    void displayExpenseBalance();
    void displayFullBalance();

public:
    BudgetManager(string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId)
        : FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomeManager = NULL;
        expenseManager = NULL;
    };
    ~BudgetManager()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    };

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
    char selectOptionFromDateMenu();
    char selectOptionFromBalanceMenu();
};

#endif
