#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    char choice;

    PersonalBudget personalBudget("users.xml", "expenses.xml", "incomes.xml");

    while (true)
    {
        if (personalBudget.isUserLoggedIn())
        {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayCurrentMonthBalance();
                break;
            case '4':
                personalBudget.displayPreviousMonthBalance();
                break;
            case '5':
                personalBudget.displaySelectedPeriodBalance();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '9':
                personalBudget.logoutUser();
                break;
            default:
                cout << endl << "No such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
