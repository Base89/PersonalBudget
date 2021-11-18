#ifndef FILEOFUSERS_H
#define FILEOFUSERS_H

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
    FileWithUsers(string fileName) : TextFile(fileName) {}

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif
