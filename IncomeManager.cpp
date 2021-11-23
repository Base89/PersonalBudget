#include "IncomeManager.h"

Income IncomeManager::getNewIncomeData()
{
    Income income;

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID);
    income.setDate(selectIncomeDate());

    cout << "Enter income source: ";
    income.setItem(AuxiliaryMethods::enterInputData());

    cout << "Enter income amount: ";
    income.setAmount(validateAmount());

}

int IncomeManager::selectIncomeDate()
{
    bool dateMenu = 0;
    char choice;
    int date = 0;

    while (dateMenu == 0)
    {
        cout << ">> Select income date <<" << endl << endl;
        choice = selectOptionFromDateMenu();

        if (choice == '1')
        {
            date = DateManager::convertDateSeparatedDashesToInt(DateManager::getCurrentDate());
            cout << "Today's date downloaded" << endl;
            dateMenu = 1;
        }
        else if (choice == '2')
        {
            cout << "Please, enter your date:";
            date = DateManager::convertDateSeparatedDashesToInt(DateManager::getUserDate());
            dateMenu = 1;
        }
        else if (choice == '9')
        {
            cout << endl << "Back to User Menu" << endl << endl;
            break;
        }
        else
        {
            cout << endl << "Incorrect choice! Try again." << endl << endl;
            dateMenu = 0;
        }
    }
    return date;
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
