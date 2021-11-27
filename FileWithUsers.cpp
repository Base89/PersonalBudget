#include "FileWithUsers.h"

User FileWithUsers::getUserData(CMarkup xml)
{
    User user;

    xml.IntoElem();

    xml.FindElem("UserId");
    MCD_STR strUserId = xml.GetData();
    user.setId(AuxiliaryMethods::convertStringToInt(strUserId));

    xml.FindElem("Login");
    MCD_STR strLogin = xml.GetData();
    user.setLogin(strLogin);

    xml.FindElem("Password");
    MCD_STR strPassword = xml.GetData();
    user.setPassword(strPassword);

    xml.FindElem("Name");
    MCD_STR strName = xml.GetData();
    user.setName(strName);

    xml.FindElem("Surname");
    MCD_STR strSurname = xml.GetData();
    user.setSurname(strSurname);

    xml.OutOfElem();

    return user;
}

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

    xml = loadFile(getFileName());

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.OutOfElem();
    xml.Save(getFileName() + ".xml");
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;
    vector <User> users;

    xml = loadFile(getFileName());
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        users.push_back(getUserData(xml));
    }
    cout << "Loaded users from file. " << endl;

    return users;
}

void FileWithUsers::saveNewUserPassword(int loggedInUserId, string newPassword)
{
    CMarkup xml;
    string userId = AuxiliaryMethods::convertIntToString(loggedInUserId);

    xml = loadFile(getFileName());

    xml.FindElem();
    xml.IntoElem();

     while (xml.FindElem("User"))
    {
        xml.FindChildElem("UserId");
        MCD_STR strUserId = xml.GetChildData();

        if (strUserId == userId)
        {

        }
    }
}
