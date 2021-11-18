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
    void sortExpensesFromEldest();
    double sumExpenses();
    void displayExpenses();
    void displayExpensesSum();
    void displayAmountOfExpenses();
    void searchExpensesBySelectedPeriod();

public:
    ExpenseManager() {}

    void addExpense();
    void displayExpenseBalance();
};

#endif
