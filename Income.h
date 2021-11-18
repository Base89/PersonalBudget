#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "Finance.h"

using namespace std;

class Income : public Finance
{
    int incomeId;

public:
    int getIncomeId();

    void setIncomeId(int newIncomeId);
};

#endif
