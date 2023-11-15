// File: Problem2.cpp
// Purpose: Both gender rewriter.
// Author: Mohamed_Taha
// Section: s22
// ID: 20221123
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1 = "";
    getline(cin, s);
    vector<string> vs;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            s1 += s[i];
        }
        else
        {
            if (s1 == "")
            {
                continue;
            }
            vs.push_back(s1);
            s1 = "";
        }
    }
    vs.push_back(s1);
    for (int i = 0; i < vs.size(); i++)
    {
        if (vs[i] == "him" || vs[i] == "Him" || vs[i] == "HIM") 
        {
            cout << vs[i] << " or her ";
        }
        else if (vs[i] == "him.")
        {
            cout << "him or her. ";
        }
        else if (vs[i] == "he" || vs[i] == "He" || vs[i] == "HE")
        {
            cout << vs[i] << " or she ";
        }
        else if (vs[i] == "he.")
        {
            cout << "he or she. ";
        }
        else
        {
            cout << vs[i] << " ";
        }
    }
    return 0;
}