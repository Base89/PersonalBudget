#include "TextFile.h"

CMarkup TextFile::loadFile()
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(getFileName()));
        cout << "Text file " << getFileName() << " has been created. " << endl << endl;
        return 0;
    }
    return xml;
}

string TextFile::getFileName()
{
    return FILE_NAME + ".xml";
}
