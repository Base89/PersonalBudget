#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    return to_string(number);
}

string AuxiliaryMethods::convertDoubleToString(double number)
{
    return to_string(number);
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    return atoi(number.c_str());
}

double AuxiliaryMethods::convertStringToDouble(string number)
{
    return atof(number.c_str());
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

string AuxiliaryMethods::saveTwoDecimalPlaces(double amount)
{
    const string COMMA = ",";
    const string DOT = ".";
    const string TWO_DECIMAL_PLACES = ".00";
    string strAmount = convertDoubleToString(amount);
    int position = 0;

    position = strAmount.find(COMMA);
    if (position == string::npos)
    {
        position = 0;
        position = strAmount.find(DOT);
        if (position != string::npos)
            return strAmount.substr (0, position + 3);
        else
            return strAmount += TWO_DECIMAL_PLACES;
    }
    else
        return strAmount.substr (0, position + 3);
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
        cout << "This is not a single character. Type again: ";
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
        cout << "This is not a number. Type again: ";
    }
    return number;
}

string AuxiliaryMethods::loadInputData()
{
    string input = "";

    getline(cin, input);
    while(!cin)
    {
        cin.clear();
        cin.ignore(160, 'n');
        getline(cin, input);
    }
    return input;
}
