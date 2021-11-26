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

    return income;
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

vector <Income> IncomeManager::sortIncomesFromEldest(vector <Income> selectedIncomes)
{
    vector <Income> sortedIncomes;

    sort(incomes.begin(), incomes.end());

    return sortedIncomes;
}

double IncomeManager::sumIncomes(vector <Income> selectedIncomes)
{
    double total = 0;
    for (int i = 0; i < selectedIncomes.size(); i++)
    {
        total += selectedIncomes[i].getAmount();
    }
    return total;
}

void IncomeManager::displayIncome(Income income)
{
    cout << endl << "Income ID:         " << income.getIncomeId() << endl;
    cout << "Date Income:       " << income.getDate() << endl;
    cout << "Source Income:     " << income.getItem() << endl;
    cout << "Amount:            " << income.getAmount() << endl;
}

void IncomeManager::displayAllIncomes(vector <Income> selectedIncomes)
{
    int amountIncomes = 0;

    system("cls");
    if (!selectedIncomes.empty())
    {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
        {
            displayIncome(*itr);
            amountIncomes++;
        }
        cout << endl;
        displayAmountOfIncomes(amountIncomes);
    }
    else
    {
        cout << endl << "No incomes." << endl << endl;
    }
    system("pause");
}

void IncomeManager::displayIncomesSum(vector <Income> selectedIncomes)
{
    cout << endl << "TOTAL INCOME:         " << sumIncomes(selectedIncomes) << endl;
}

void IncomeManager::displayAmountOfIncomes(int amountIncomes)
{
    if (amountIncomes == 0)
        cout << endl << "No income." << endl;
    else
        cout << endl << "The amount of income is: " << amountIncomes << endl << endl;
}

vector <Income> IncomeManager::searchIncomesBySelectedPeriod(int startingDate, int closingDate)
{
    vector <Income> selectedIncomes;

    for ( vector <Income>::iterator itr = incomes.begin(); itr < incomes.end(); itr++)
    {
        if ((itr->Income::getDate() >= startingDate) && (itr->Income::getDate() <= closingDate))
        {
            selectedIncomes.push_back(*itr);
        }
    }
    return selectedIncomes;
}

char IncomeManager::selectOptionFromDateMenu()
{
    cout << "1 - Today's date" << endl;
    cout << "2 - Other date" << endl;
    cout << "9 - Back " << endl;
    cout << endl << "Your choice: ";

    return AuxiliaryMethods::loadChar();
}

void IncomeManager::addIncome()
{

}

void IncomeManager::displayIncomeBalance()
{

}
