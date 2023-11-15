// File: Problem1_.cpp
// Purpose: space_corrector.
// Author: Sherif_mahmoud
// Section: s21
// ID: 20221080
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1 = "";
    getline(cin, s);
    vector<string> vs;
    for (int i = 0; i < s.length(); i++)
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
            transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
            vs.push_back(s1);
            s1 = "";
        }
    }
    vs.push_back(s1);
    vs[0][0] = toupper(vs[0][0]);
    for (auto i : vs)
    {
        cout << i << ' ';
    }
    return 0;
}