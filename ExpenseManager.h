#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

#include "Expense.h"
#include "FinanceManager.h"
#include "FileWithExpenses.h"
#include "DateManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpenseManager : public FinanceManager
{
    const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;

    Expense getNewExpenseData();
    vector <Expense> sortExpensesFromEldest(vector <Expense> selectedExpenses);
    double sumExpenses(vector <Expense> selectedExpenses);
    void displayExpense(Expense expense);
    void displayAllExpenses(vector <Expense> selectedExpenses);
    void displayExpensesSum(vector <Expense> selectedExpenses);
    void displayAmountOfExpenses(int amountExpenses);
    vector <Expense> searchExpensesBySelectedPeriod(int startingDate, int closingDate);

public:
    ExpenseManager(string fileNameWithExpenses, int loggedInUserId) : fileWithExpenses(fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
    {
        expenses = fileWithExpenses.loadExpensesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };

    void addExpense();
    void displayExpenseBalanceOfCurrentMonth();
    void displayExpenseBalanceOfPreviousMonth();
    void displayExpenseBalanceOfSelectedPeriod();
};

#endif
