#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    cout << "String: ";
    string str;
    cin.ignore(); 
    getline(cin, str);
    return str;
}

char ReadChar()
{
    char c;
    cout << "Char: ";
    cin >> c;
    return c;
}

void CountLetter(char c, string str)
{
    int counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            counter++;
        }
    }
    cout << "The letter '" << c << "' exists " << counter << " times." << endl;
}

char Invert(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}

void PrintFirstLetter(string str)
{
    bool IsFirstLetter = true;
    cout << "\nFirst letters of each word:\n";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && IsFirstLetter)
        {
            cout << str[i] << endl;
        }
        IsFirstLetter = (str[i] == ' ');
    }
}

string CapitalizeFirstLetter(string str)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && IsFirstLetter)
        {
            str[i] = toupper(str[i]);
        }
        IsFirstLetter = (str[i] == ' ');
    }
    return str;
}

string LowerFirstLetter(string str)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && IsFirstLetter)
        {
            str[i] = tolower(str[i]);
        }
        IsFirstLetter = (str[i] == ' ');
    }
    return str;
}

void UpperAll(string str)
{
    cout << "\nUppercase version:\n";
    for (int i = 0; i < str.length(); i++)
    {
        cout << (char)toupper(str[i]);
    }
    cout << endl;
}

void LowerAll(string str)
{
    cout << "\nLowercase version:\n";
    for (int i = 0; i < str.length(); i++)
    {
        cout << (char)tolower(str[i]);
    }
    cout << endl;
}

void Invert(string str)
{
    cout << "\nInverted case:\n";
    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
            cout << (char)tolower(str[i]);
        else if (islower(str[i]))
            cout << (char)toupper(str[i]);
        else
            cout << str[i];
    }
    cout << endl;
}

void CountThemAll(string str)
{
    int Ccounter = 0;
    int Lcounter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i])) Ccounter++;
        else if (islower(str[i])) Lcounter++;
    }
    cout << "\nCapital letters count: " << Ccounter << endl;
    cout << "Small letters count: " << Lcounter << endl;
    cout << "All letters count: " << Ccounter + Lcounter << endl;
}

int main()
{
    string str = ReadString();
    char c = ReadChar();

    cout << endl;
    CountLetter(c, str);
    PrintFirstLetter(str);

    cout << "\nCapitalized first letters:\n" << CapitalizeFirstLetter(str) << endl;
    cout << "\nLowercased first letters:\n" << LowerFirstLetter(str) << endl;

    UpperAll(str);
    LowerAll(str);
    Invert(str);
    CountThemAll(str);

    return 0;
}
