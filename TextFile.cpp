#include "TextFile.h"

void TextFile::loadFile()
{
    bool fileExists = xml.Load( getFileName() + ".xml" );

    if (!fileExists)
    {
        xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
        xml.AddElem( AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(getFileName()) );
    }
}

string TextFile::getFileName()
{
    return FILE_NAME;
}
