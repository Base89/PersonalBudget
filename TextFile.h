#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>

#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class TextFile
{
    const string FILE_NAME;
    CMarkup xml;

public:
    TextFile(string fileName) : FILE_NAME(fileName) {}

    void loadFile();
    string getFileName();

};

#endif
