#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>

#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class TextFile
{
    const string FILE_NAME;

public:
    TextFile(string fileName) : FILE_NAME(fileName) {}

    CMarkup loadFile();
    string getFileName();

};

#endif
