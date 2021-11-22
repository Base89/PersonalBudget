#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "FinanceManager.h"
#include "FileWithExpenses.h"

using namespace std;

class ExpenseManager : public FinanceManager
{
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;

    Expense getNewExpenseData();
    vector <Expense> sortExpensesFromEldest(vector <Expense> expenses);
    double sumExpenses();
    void displayExpenses();
    void displayExpensesSum();
    void displayAmountOfExpenses();
    vector <Expense> searchExpensesBySelectedPeriod(int startingDate, int closingDate);

public:
    ExpenseManager(string fileNameWithExpenses) : fileWithExpenses(fileNameWithExpenses) {}

    void addExpense();
    void displayExpenseBalance();
};

#endif
