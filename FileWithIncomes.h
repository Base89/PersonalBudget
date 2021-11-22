#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "TextFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes : public TextFile
{
    int lastIncomeId;

    Income getIncomeData(CMarkup xml);
    int getLastIncomeIdFromFile(CMarkup xml);

public:
    FileWithIncomes(string fileName) : TextFile (fileName)
    {
        lastIncomeId = 0;
    }

    void addIncomeToFile(Income income);
    vector <Income> loadIncomesOfLoggedInUserFromFile(int loggedInUserId);
    int getLastIncomeId();
};

#endif
