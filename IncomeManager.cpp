#include "IncomeManager.h"

Income IncomeManager::getNewIncomeData()
{
    Income income;

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID);
    income.setDate(selectDate());

    cout << "Enter income source: ";
    income.setItem(AuxiliaryMethods::enterInputData());

    cout << "Enter income amount: ";
    income.setAmount(validateAmount());

    return income;
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
    cout << "Amount:            " << fixed << setprecision(2) << income.getAmount() << endl;
}

void IncomeManager::displayAllIncomes(vector <Income> selectedIncomes)
{
    int amountIncomes = 0;

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
}

void IncomeManager::displayIncomesSum(vector <Income> selectedIncomes)
{
    cout << "TOTAL INCOME:      " << fixed << setprecision(2) << sumIncomes(selectedIncomes) << endl << endl;
}

void IncomeManager::displayAmountOfIncomes(int amountIncomes)
{
    if (amountIncomes == 0)
        cout << "No income." << endl << endl;
    else
        cout << "The amount of income is: " << amountIncomes << endl << endl;
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

void IncomeManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = getNewIncomeData();

    incomes.push_back(income);
    if (fileWithIncomes.addIncomeToFile(income))
        cout << "New income has been added." << endl;
    else
        cout << "Error! New income has not been added." << endl;
    system("pause");
}

void IncomeManager::displayIncomeBalanceOfCurrentMonth()
{
    vector <Income> currentMonthIncomes;
    int firstDate = AuxiliaryMethods::convertStringToInt(DateManager::getFirstDayOfMonth(DateManager::getCurrentDate()));
    int lastDate = DateManager::convertDateSeparatedDashesToInt(DateManager::getCurrentDate());

    currentMonthIncomes = searchIncomesBySelectedPeriod(firstDate, lastDate);
    displayAllIncomes(currentMonthIncomes);
    displayIncomesSum(currentMonthIncomes);
    system("pause");
}

void IncomeManager::displayIncomeBalanceOfPreviousMonth()
{
    vector <Income> previousMonthIncomes;
    int firstDate = AuxiliaryMethods::convertStringToInt(DateManager::getFirstDayOfPreviousMonth());
    int lastDate = AuxiliaryMethods::convertStringToInt(DateManager::getLastDayOfMonth(DateManager::getFirstDayOfPreviousMonth()));

    previousMonthIncomes = searchIncomesBySelectedPeriod(firstDate, lastDate);
    displayAllIncomes(previousMonthIncomes);
    displayIncomesSum(previousMonthIncomes);
    system("pause");
}

void IncomeManager::displayIncomeBalanceOfSelectedPeriod(int firstDate, int lastDate)
{
    vector <Income> selectedPeriodIncomes;

    selectedPeriodIncomes = searchIncomesBySelectedPeriod(firstDate, lastDate);
    displayAllIncomes(selectedPeriodIncomes);
    displayIncomesSum(selectedPeriodIncomes);
    system("pause");
}
