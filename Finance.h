#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>

#include "AuxiliaryMethods.h"

using namespace std;

class Finance
{
    int userId;
    int date;
    string item;
    double amount;

public:
    bool operator < (const Finance &secondDate) const;
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};

#endif
