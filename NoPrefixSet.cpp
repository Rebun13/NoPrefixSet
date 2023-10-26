#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
/**
// SOLUTION 1

bool isPrefix(string a, string b)
{
    // same length
    if (a.length() > b.length())
    {
        return a == b;
    }
    // a longer than b
    if (a.length() > b.length())
    {
        return b == a.substr(0, b.length());
    }
    // b longer than a
    return a == b.substr(0, a.length());
}

//
// The function accepts STRING_ARRAY words as parameter.
//
void noPrefix(vector<string> words)
{
    for (int i = 0; i < words.size() - 1; i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (isPrefix(words.at(i), words.at(j)))
            {
                cout << "BAD SET" << endl;
                cout << words.at(i) << endl;
                return;
            }
        }
    }
    cout << "GOOD SET" << endl;
}
*/

// SOLUTION 2
bool isPrefix(string s, string prefix)
{
    // same length
    if (s == prefix)
    {
        return true;
    }

    // a longer than b
    return prefix == s.substr(0, prefix.length());
}

/*
* The function accepts STRING_ARRAY words as parameter.
*/
void noPrefix(vector<string> words)
{
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if(i != j && words.at(i).size() >= words.at(j).size()){
                if (isPrefix(words.at(i), words.at(j)))
                {
                    cout << "BAD SET" << endl << words.at(i) << endl;
                    return;
                }
            }
        }
    }
    cout << "GOOD SET" << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int c)
                { return !std::isspace(c); }));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int c)
                { return !std::isspace(c); })
            .base(),
        s.end());

    return s;
}
