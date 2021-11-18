#include "Income.h"

int Income::getIncomeId()
{
    return incomeId;
}

void Income::setIncomeId(int newIncomeId)
{
    if (newIncomeId > 0)
        incomeId = newIncomeId;
}
