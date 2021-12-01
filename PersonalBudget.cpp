#include "PersonalBudget.h"

char PersonalBudget::selectOptionFromMainMenu()
{
    system("cls");
    cout << "    >>>  MAIN  MENU  <<<" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "----------------------------" << endl;
    cout << "Your choice: ";

    return AuxiliaryMethods::loadChar();
}

char PersonalBudget::selectOptionFromUserMenu()
{
    system("cls");
    cout << " >>>  USER  MENU  <<<" << endl;
    cout << "----------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show balance for current month" << endl;
    cout << "4. Show balance for previous month" << endl;
    cout << "5. Show balance for selected period" << endl;
    cout << "----------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "----------------------" << endl;
    cout << "Your choice: ";

    return AuxiliaryMethods::loadChar();
}

void PersonalBudget::displayAllUsers()
{
    userManager.displayAllUsers();
}

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
        budgetManager = new BudgetManager(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getLoggedInUserId());
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}

void PersonalBudget::logoutUser()
{
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

bool PersonalBudget::isUserLoggedIn()
{
    return (!userManager.isUserLoggedIn()) ? true : false;
}

void PersonalBudget::displayInfoForNotLoggingUser()
{
    cout << "You must be logged in to perform this operation." << endl;
    system("pause");
}

void PersonalBudget::addIncome()
{
    if (userManager.isUserLoggedIn())
        budgetManager->addIncome();
    else
    {
        displayInfoForNotLoggingUser();
    }
}

void PersonalBudget::addExpense()
{
    if (userManager.isUserLoggedIn())
        budgetManager->addExpense();
    else
    {
        displayInfoForNotLoggingUser();
    }
}

void PersonalBudget::displayCurrentMonthBalance()
{
    if (userManager.isUserLoggedIn())
        budgetManager->displayCurrentMonthBalance();
    else
    {
        displayInfoForNotLoggingUser();
    }
}

void PersonalBudget::displayPreviousMonthBalance()
{
    if (userManager.isUserLoggedIn())
        budgetManager->displayPreviousMonthBalance();
    else
    {
        displayInfoForNotLoggingUser();
    }
}

void PersonalBudget::displaySelectedPeriodBalance()
{
    if (userManager.isUserLoggedIn())
        budgetManager->displaySelectedPeriodBalance();
    else
    {
        displayInfoForNotLoggingUser();
    }
}
