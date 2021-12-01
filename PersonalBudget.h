#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "FileWithUsers.h"
#include "FileWithExpenses.h"
#include "FileWithIncomes.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string FILE_NAME_WITH_EXPENSES;
    const string FILE_NAME_WITH_INCOMES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithExpenses, string fileNameWithIncomes)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses), FILE_NAME_WITH_INCOMES(fileNameWithIncomes)
    {
        budgetManager = NULL;
    };
    ~PersonalBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    };

    void displayAllUsers();
    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();
    bool isUserLoggedIn();
    void displayInfoForNotLoggingUser();
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};

#endif
