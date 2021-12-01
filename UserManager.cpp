#include "UserManager.h"

User UserManager::getNewUserData()
{
    User user;

    user.setId(getNewUserId());

    do
    {
        cout << endl << "Enter login: ";
        user.setLogin(AuxiliaryMethods::loadInputData());
    }
    while (isLoginExists(user.getLogin()));

    string password, name, surname;
    cout << "Enter password: ";
    user.setPassword(AuxiliaryMethods::loadInputData());

    cout << "Enter name: ";
    user.setName(AuxiliaryMethods::loadInputData());

    cout << "Enter surname: ";
    user.setSurname(AuxiliaryMethods::loadInputData());

    return user;
}

int UserManager::getNewUserId()
{
    return users.empty() ? 1 : (users.back().getId() + 1);
}

bool UserManager::isLoginExists(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "The given login is taken." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::registerUser()
{
    User user;
    user = getNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Account has been successfully created." << endl << endl;
    system("pause");
}

void UserManager::loginUser()
{
    string login, password = "";

    cout << endl << "Enter your login: ";
    login = AuxiliaryMethods::loadInputData();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getLogin() == login)
        {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber-- )
            {
                if (attemptsNumber < 3)
                    cout << "Remaining attempts: " << attemptsNumber << endl;
                cout << "Enter your password: ";
                password = AuxiliaryMethods::loadInputData();

                if (itr->getPassword() == password)
                {
                    loggedInUserId = itr->getId();
                    return;
                }
            }
            cout << "Incorrect password entered 3 times." << endl;
            system ("pause");
            return;
        }
        itr++;
    }
    cout << "The user with the given login does not exist." << endl << endl;
    system ("pause");
    return;
}

void UserManager::displayAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
    system("pause");
}

void UserManager::changePassword()
{
    string newPassword = "";

    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::loadInputData();

    if(isUserLoggedIn())
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            if (itr->getId() == loggedInUserId)
            {
                itr->setPassword(newPassword);
                cout << "Your password has been changed." << endl << endl;
                system("pause");
            }
        }
        fileWithUsers.saveNewUserPassword(loggedInUserId, newPassword);
    }
    else
    {
        cout << "You must log in to change your password." << endl;
        system("pause");
    }
}

void UserManager::logoutUser()
{
    loggedInUserId = 0;

    cout << endl << "Logged out." << endl;
    system("pause");
}

bool UserManager::isUserLoggedIn()
{
    return (loggedInUserId > 0) ? 1 : 0;
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}
