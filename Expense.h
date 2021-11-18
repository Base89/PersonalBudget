#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "Finance.h"

using namespace std;

class Expense : public Finance
{
    int expenseId;

public:
    int getExpenseId();

    void setExpenseId(int newExpenseId);
};

#endif
