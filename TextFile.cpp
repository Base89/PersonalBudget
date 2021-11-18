#include "TextFile.h"

CMarkup TextFile::loadFile(string fileName)
{
    CMarkup xml;

    bool fileExists = xml.Load(fileName + ".xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(getFileName()));
        cout << "Text file " << fileName << ".xml " << "was created. " << endl;
        return 0;
    }
    return xml;
}

string TextFile::getFileName()
{
    return FILE_NAME;
}
