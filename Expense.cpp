#include "Expense.h"

int Expense::getExpenseId()
{
    return expenseId;
}

void Expense::setExpenseId(int newExpenseId)
{
    if (newExpenseId > 0)
        expenseId = newExpenseId;
}
