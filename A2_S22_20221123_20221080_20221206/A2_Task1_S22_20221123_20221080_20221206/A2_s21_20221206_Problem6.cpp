// File: Problem6.cpp
// Purpose: Probabilities of binary numbers.
// Author: Youssif_waleed
// Section: s21
// ID: 20221206
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
string binary(int n, string s)
{
    if (n == 0)
    {
        return "0" + s;
    }
    else
    {
        if (n % 2 == 0)
        {
            return binary(n / 2, "0" + s);
        }
        else
        {
            return binary(n / 2, "1" + s);
        }
    }
}
string ss;
int n, c;
void numbers(string Prefix, int k)
{
    if (c == pow(2, k))
    {
        return;
    }
    if (Prefix.size() == ss.size() + k)
    {
        c++;
        cout << Prefix << endl;
    }
    else
    {
        numbers(Prefix + "0", k);
        numbers(Prefix + "1", k);
    }
}
int main()
{
    int k;
    cin >> n >> k;
    ss = binary(n, "");
    numbers(ss, k);
}