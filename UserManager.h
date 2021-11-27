#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User getNewUserData();
    int getNewUserId();
    bool isLoginExists(string login);

public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers)
    {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void registerUser();
    void loginUser();
    void displayAllUsers();
    void changePassword();
    void logoutUser();
    bool isUserLoggedIn();
    int getLoggedInUserId();
};

#endif
