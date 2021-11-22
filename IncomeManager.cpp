#include "IncomeManager.h"

Income IncomeManager::getNewIncomeData()
{
    Income income;
    int date = 0;
    string item = "";
    double amount = 0;

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to select today's date for income? (y / n)";

    cout << "Enter income date: ";

    cout << "Enter income source: ";

    cout << "Enter income amount: ";

}

vector <Income> IncomeManager::sortIncomesFromEldest(vector <Income> incomes)
{

}

double IncomeManager::sumIncomes()
{

}

void IncomeManager::displayIncomes()
{

}

void IncomeManager::displayIncomesSum()
{

}

void IncomeManager::displayAmountOfIncomes()
{

}

vector <Income> IncomeManager::searchIncomesBySelectedPeriod(int startingDate, int closingDate)
{

}

void IncomeManager::addIncome()
{

}

void IncomeManager::displayIncomeBalance()
{

}
