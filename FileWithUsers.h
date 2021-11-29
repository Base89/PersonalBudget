#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "TextFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers : public TextFile
{
    User getUserData(CMarkup xml);

public:
    FileWithUsers(string fileNameWithUsers) : TextFile(fileNameWithUsers) {}

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveNewUserPassword(int loggedInUserId, string newPassword);
};

#endif
