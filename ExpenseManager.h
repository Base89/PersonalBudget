#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "FinanceManager.h"

using namespace std;

class ExpenseManager : public FinanceManager
{
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;
};

#endif
