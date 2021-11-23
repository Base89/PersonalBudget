#include "IncomeManager.h"

Income IncomeManager::getNewIncomeData()
{
    Income income;
    int date = 0;
    string item = "";
    double amount = 0;
    char choice;

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID);

    cout << ">> Select income date <<" << endl << endl;
    choice = selectOptionFromDateMenu();

    if (choice == '1')
    {

        cout << "Today's date downloaded" << endl;
    }
    else if (choice == '2')
    {
        cout << "Enter your date: ";
    }
    else if (choice == '9')
    {
        cout << endl << "Back to User Menu" << endl << endl;
    }
    else
    {
        cout << endl << "Incorrect choice. Back to User Menu." << endl << endl;
    }

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

char IncomeManager::selectOptionFromDateMenu()
{
    char choice;

    cout << "1 - Today's date" << endl;
    cout << "2 - Other date" << endl;
    cout << "9 - Back " << endl;
    cout << endl << "Your choice: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

void IncomeManager::addIncome()
{

}

void IncomeManager::displayIncomeBalance()
{

}
