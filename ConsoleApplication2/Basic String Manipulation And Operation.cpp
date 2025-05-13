#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    cout << "Enter a string: ";
    string str;
    cin.ignore();
    getline(cin, str);
    return str;
}

char ReadChar()
{
    char c;
    cout << "Enter a character: ";
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

void CountCase(char c, string str, bool CaseSens = true)
{
    short counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        if (CaseSens)
        {
            if (str[i] == c)
                counter++;
        }
        else
        {
            if (tolower(c) == tolower(str[i]))
                counter++;
        }
    }
    cout << c << " exists " << counter << " times." << endl;
}

bool IsVowel(char a)
{
    char c = tolower(a);
    return  ((c == 'a') || (c == 'e') || (c == 'u') || (c == 'i') || (c == 'o'));
}

short CountVowel(char c, string str)
{
    short counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
            counter++;
    }
    return counter;
}

void PrintWords(string str)
{
    string space = " ";
    short pos = 0;
    short count = 0;
    while ((pos = str.find(space)) != std::string::npos)
    {
        string sub = str.substr(0, pos);
        if (sub != "")
        {
            cout << sub << endl;
        }
        str.erase(0, pos + space.length());
    }
    if (str != "")
    {
        cout << str << endl;
    }
}

short CountWords(string str)
{
    string space = " ";
    short pos = 0;
    short count = 0;
    while ((pos = str.find(space)) != std::string::npos)
    {
        string sub = str.substr(0, pos);
        if (sub != "")
        {
            count++;
        }
        str.erase(0, pos + space.length());
    }
    if (str != "")
    {
        count++;
    }
    return count;
}

void PrintVowels(char c, string str)
{
    for (short i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
            cout << str[i] << " ";
    }
    cout << endl;
}

vector<string> SplitString(string str, string n)
{
    vector<string> vec;
    string dil = n;
    short pos = 0;
    short tokens = 0;
    string sword = "";

    while ((pos = str.find(dil)) != std::string::npos)
    {
        sword = str.substr(0, pos);
        if (sword != "")
        {
            vec.push_back(sword);
            tokens++;
        }
        str.erase(0, pos + dil.length());
    }

    if (str != "")
    {
        vec.push_back(str);
        tokens++;
    }
    cout << "Tokens: " << tokens;
    return vec;
}

string TrimLeft(string str)
{
    for (short i = 0; i < str.length() - 1; i++)
    {
        if (str[i] != ' ')
            return str.substr(i, str.length() - i);
    }
}

string TrimRight(string str)
{
    for (short i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
            return str.substr(0, i + 1);
    }
    return str;
}

string Trim(string str)
{
    return TrimLeft(TrimRight(str));
}

string Join(vector <string> names, string del = " ")
{
    string s = "";
    for (string& holder : names)
    {
        s += holder + del;
    }
    return s.substr(0, s.length() - del.length());
}

int main()
{
    string str = ReadString();
    char c = ReadChar();

    CountLetter(c, str);
    PrintFirstLetter(str);
    cout << "\nCapitalized first letters:\n" << CapitalizeFirstLetter(str) << endl;
    cout << "\nLowercased first letters:\n" << LowerFirstLetter(str) << endl;
    UpperAll(str);
    LowerAll(str);
    Invert(str);
    CountThemAll(str);
    CountCase(c, str);
    PrintWords(str);
    cout << "Word count: " << CountWords(str) << endl;
    PrintVowels(c, str);
    vector<string> words = SplitString(str, " ");
    cout << "\nTrimmed string: " << Trim(str) << endl;
    cout << "Joined words: " << Join(words) << endl;

    return 0;
}
