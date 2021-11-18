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
