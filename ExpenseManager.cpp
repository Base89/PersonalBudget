#include "ExpenseManager.h"

Expense ExpenseManager::getNewExpenseData()
{
    Expense expense;

    expense.setExpenseId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setDate(selectDate());

    cout << "Enter expense source: ";
    expense.setItem(AuxiliaryMethods::loadInputData());

    cout << "Enter expense amount: ";
    expense.setAmount(validateAmount());

    return expense;
}

vector <Expense> ExpenseManager::sortExpensesFromEldest(vector <Expense> selectedExpenses)
{
    vector <Expense> sortedExpenses;

    sort(expenses.begin(), expenses.end());

    return sortedExpenses;
}

double ExpenseManager::sumExpenses(vector <Expense> selectedExpenses)
{
    double total = 0;
    for (int i = 0; i < selectedExpenses.size(); i++)
    {
        total += selectedExpenses[i].getAmount();
    }
    setSumSelectedExpenses(total);
    return total;
}

void ExpenseManager::displayExpense(Expense expense)
{
    cout << endl << "Expense ID:         " << expense.getExpenseId() << endl;
    cout << "Date Expense:       " << DateManager::convertIntDateToDateWithDashes(expense.getDate()) << endl;
    cout << "Source Expense:     " << expense.getItem() << endl;
    cout << "Amount:             " << fixed << setprecision(2) << expense.getAmount() << endl;
}

void ExpenseManager::displayAllExpenses(vector <Expense> selectedExpenses)
{
    int amountExpenses = 0;

    if (!selectedExpenses.empty())
    {
        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
        {
            displayExpense(*itr);
            amountExpenses++;
        }
        cout << endl;
        displayAmountOfExpenses(amountExpenses);
    }
    else
    {
        cout << endl << "No expenses." << endl << endl;
    }
}

void ExpenseManager::displayExpensesSum(vector <Expense> selectedExpenses)
{
    cout << "TOTAL EXPENSE:      " << fixed << setprecision(2) << sumExpenses(selectedExpenses) << endl << endl;
}

void ExpenseManager::displayAmountOfExpenses(int amountExpenses)
{
    if (amountExpenses == 0)
        cout << "No expense." << endl << endl;
    else
        cout << "The amount of expense is: " << amountExpenses << endl << endl;
}

vector <Expense> ExpenseManager::searchExpensesBySelectedPeriod(int startingDate, int closingDate)
{
    vector <Expense> selectedExpenses;

    for ( vector <Expense>::iterator itr = expenses.begin(); itr < expenses.end(); itr++)
    {
        if ((itr->Expense::getDate() >= startingDate) && (itr->Expense::getDate() <= closingDate))
        {
            selectedExpenses.push_back(*itr);
        }
    }
    return selectedExpenses;
}

void ExpenseManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = getNewExpenseData();

    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
    cout << "New expense has been added." << endl;

    system("pause");
}

void ExpenseManager::displayExpenseBalanceOfCurrentMonth()
{
    vector <Expense> currentMonthExpenses;
    int firstDate = AuxiliaryMethods::convertStringToInt(DateManager::getFirstDayOfMonth(DateManager::getCurrentDate()));
    int lastDate = DateManager::convertDateSeparatedDashesToInt(DateManager::getCurrentDate());

    currentMonthExpenses = searchExpensesBySelectedPeriod(firstDate, lastDate);
    displayAllExpenses(currentMonthExpenses);
    displayExpensesSum(currentMonthExpenses);
}

void ExpenseManager::displayExpenseBalanceOfPreviousMonth()
{
    vector <Expense> previousMonthExpenses;
    int firstDate = AuxiliaryMethods::convertStringToInt(DateManager::getFirstDayOfPreviousMonth());
    int lastDate = AuxiliaryMethods::convertStringToInt(DateManager::getLastDayOfMonth(DateManager::getFirstDayOfPreviousMonth()));

    previousMonthExpenses = searchExpensesBySelectedPeriod(firstDate, lastDate);
    displayAllExpenses(previousMonthExpenses);
    displayExpensesSum(previousMonthExpenses);
}

void ExpenseManager::displayExpenseBalanceOfSelectedPeriod(int firstDate, int lastDate)
{
    vector <Expense> selectedPeriodExpenses;

    selectedPeriodExpenses = searchExpensesBySelectedPeriod(firstDate, lastDate);
    displayAllExpenses(selectedPeriodExpenses);
    displayExpensesSum(selectedPeriodExpenses);
}

void ExpenseManager::setSumSelectedExpenses(double newSumSelectedExpenses)
{
    sumSelectedExpenses = newSumSelectedExpenses;
}

double ExpenseManager::getSumSelectedExpenses()
{
    return sumSelectedExpenses;
}
