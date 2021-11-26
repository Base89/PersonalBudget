#include "FileWithIncomes.h"

Income FileWithIncomes::getIncomeData(CMarkup xml)
{
    Income income;

    xml.IntoElem();

    xml.FindElem("IncomeId");
    MCD_STR strIncomeId = xml.GetData();
    income.setIncomeId(AuxiliaryMethods::convertStringToInt(strIncomeId));

    xml.FindElem("UserId");
    MCD_STR strUserId = xml.GetData();
    income.setUserId(AuxiliaryMethods::convertStringToInt(strUserId));

    xml.FindElem("Date");
    MCD_STR strDate = xml.GetData();
    income.setDate(AuxiliaryMethods::convertStringToInt(strDate));

    xml.FindElem("Item");
    MCD_STR strItem = xml.GetData();
    income.setItem(strItem);

    xml.FindElem("Amount");
    MCD_STR strAmount = xml.GetData();
    income.setAmount(AuxiliaryMethods::convertStringToDouble(strAmount));

    xml.OutOfElem();

    return income;
}

int FileWithIncomes::getLastIncomeIdFromFile(CMarkup xml)
{
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Income")) {}

    xml.IntoElem();

    xml.FindElem("IncomeId");
    MCD_STR strIncomeId = xml.GetData();

    return AuxiliaryMethods::convertStringToInt(strIncomeId);
}

bool FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    xml = loadFile(getFileName());

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.OutOfElem();
    xml.Save(getFileName() + ".xml");

    lastIncomeId++;
}

vector <Income> FileWithIncomes::loadIncomesOfLoggedInUserFromFile(int loggedInUserId)
{
    CMarkup xml;
    vector <Income> incomes;
    string userId = AuxiliaryMethods::convertIntToString(loggedInUserId);

    xml = loadFile(getFileName());
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Income"))
    {
        xml.FindChildElem("UserId");
        MCD_STR strUserId = xml.GetChildData();

        if (strUserId == userId)
        {
            incomes.push_back(getIncomeData(xml));
        }
    }
    lastIncomeId = getLastIncomeIdFromFile(xml);
    cout << "Loaded incomes from file. " << endl;

    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}
