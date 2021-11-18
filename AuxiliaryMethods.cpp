#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream oss;
    oss << number;
    string strNumber = oss.str();

    return strNumber;
}

string AuxiliaryMethods::convertDoubleToString(double number)
{
    ostringstream oss;
    oss << number;
    string strNumber = oss.str();

    return strNumber;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int intNumber = 0;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

double AuxiliaryMethods::convertStringToDouble(string number)
{
    double doubleNumber = 0;
    istringstream iss(number);
    iss >> doubleNumber;

    return doubleNumber;
}

string AuxiliaryMethods::changeCommaForDot(string numberWithComma)
{
    string numberWithDot = "";
    const string COMMA = ",";
    const string DOT = ".";
    int position = 0;

    position = numberWithComma.find(COMMA);
    if (position != string::npos)
    {
        numberWithDot = numberWithComma.replace(position, 1, DOT, 0, 1);
    }
    else
        return numberWithComma;

    return numberWithDot;
}

string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char AuxiliaryMethods::loadChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Type again. " << endl;
    }
    return character;
}

int AuxiliaryMethods::loadInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "This is not a number. Type again. " << endl;
    }
    return number;
}

string AuxiliaryMethods::enterInputData()
{
    string inputData = "";

    cin.ignore();
    getline(cin, inputData);

    return inputData;
}
