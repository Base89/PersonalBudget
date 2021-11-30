#include "BudgetManager.h"

void BudgetManager::displayCurrentMonthBalanceHeader()
{
    system("cls");
    cout << "             >>> FINANCIAL BALANCE OF THIS MONTH <<<" << endl;
    cout << "------------------------------------------------------------------" << endl << endl;
}

void BudgetManager::displayPreviousMonthBalanceHeader()
{
    system("cls");
    cout << "             >>> FINANCIAL BALANCE OF PREVIOUS MONTH <<<" << endl;
    cout << "---------------------------------------------------------------------" << endl << endl;
}

void BudgetManager::displaySelectedPeriodBalanceHeader()
{
    system("cls");
    cout << "             >>> FINANCIAL BALANCE OF SELECTED PERIOD <<<" << endl;
    cout << "-----------------------------------------------------------------------" << endl << endl;
}

void BudgetManager::addIncome()
{
    incomeManager->addIncome();
}

void BudgetManager::addExpense()
{
    expenseManager->addExpense();
}

void BudgetManager::displayCurrentMonthBalance()
{
    displayCurrentMonthBalanceHeader();
    incomeManager->displayIncomeBalanceOfCurrentMonth();
    expenseManager->displayExpenseBalanceOfCurrentMonth();
    cout << endl << "TOTAL BALANCE: " << fixed << setprecision(2) << (incomeManager->getSumSelectedIncomes() - expenseManager->getSumSelectedExpenses()) << endl << endl;
    system("pause");
}

void BudgetManager::displayPreviousMonthBalance()
{
    displayPreviousMonthBalanceHeader();
    incomeManager->displayIncomeBalanceOfPreviousMonth();
    expenseManager->displayExpenseBalanceOfPreviousMonth();
    cout << endl << "TOTAL BALANCE: " << fixed << setprecision(2) << (incomeManager->getSumSelectedIncomes() - expenseManager->getSumSelectedExpenses()) << endl << endl;
    system("pause");
}

void BudgetManager::displaySelectedPeriodBalance()
{
    cout << endl << "Enter starting date: " << endl;
    int firstDate = DateManager::convertDateSeparatedDashesToInt(DateManager::getUserDate());
    cout << endl << "Enter ending date: " << endl;
    int lastDate = DateManager::convertDateSeparatedDashesToInt(DateManager::getUserDate());

    displaySelectedPeriodBalanceHeader();
    incomeManager->displayIncomeBalanceOfSelectedPeriod(firstDate, lastDate);
    expenseManager->displayExpenseBalanceOfSelectedPeriod(firstDate, lastDate);
    cout << endl << "TOTAL BALANCE: " << fixed << setprecision(2) << (incomeManager->getSumSelectedIncomes() - expenseManager->getSumSelectedExpenses()) << endl << endl;
    system("pause");
}
