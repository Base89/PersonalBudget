#include "Finance.h"

int Finance::getUserId()
{
    return userId;
}

int Finance::getDate()
{
    return date;
}

string Finance::getItem()
{
    return item;
}

double Finance::getAmount()
{
    return amount;
}

void Finance::setUserId(int newUserId)
{
    if (newUserId > 0)
        userId = newUserId;
}

void Finance::setDate(int newDate)
{
    const int BORDER_DATE = 20000000;
    if (newDate > BORDER_DATE)
        date = newDate;
}

void Finance::setItem(string newItem)
{
    item = newItem;
}

void Finance::setAmount(double newAmount)
{
    if (newAmount > 0)
        amount = newAmount;
}
