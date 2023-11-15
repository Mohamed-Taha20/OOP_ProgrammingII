// File: Problem3_.cpp
// Purpose: Delete_delimiter.
// Author: Youssif_waleed
// Section: s21
// ID: 20221206
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
// vector<string> split(string target, string delimiter);
vector<string> vs;
void split(string str, string str1)
{
    while (str.find(str1) != string::npos)
    {
        vs.push_back(str.substr(0, str.find(str1)));
        str = str.substr(str.find(str1) + str1.length());
    }
    str = str.substr(str.find(str1) + str1.length());
    vs.push_back(str.substr(0, str.find(str1)));
}
int main()
{
    string s, s1;
    getline(cin, s);
    s1 = getchar();
    split(s, s1);
    cout << "vector elemnts are: " ;
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << ' ';
    }
}