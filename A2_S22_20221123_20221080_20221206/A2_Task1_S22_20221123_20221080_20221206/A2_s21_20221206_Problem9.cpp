// File: Problem9.cpp
// Purpose: Teddy Bear Picnic.
// Author: Youssif_waleed
// Section: s21
// ID: 20221206
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
map<int, bool> fine;
bool bears(int n)
{
    if (n == 42)
    {
        return true;
    }
    if (n < 42)
    {
        return false;
    }
    if (n % 2 == 0)
    {
        if (!fine[n - (n / 2)])
        {
            fine[n - (n / 2)] = true;
            if (bears(n - (n / 2)))
            {
                return true;
            }
        }
    }
    if (n % 3 == 0 || n % 4 == 0)
    {
        long long st, sec, mult;
        st = n % 10;
        sec = (n % 100) / 10;
        mult = st * sec;
        if (!fine[n - mult])
        {
            fine[n - mult] = true;
            if (bears(n - mult))
            {
                return true;
            }
        }
    }
    if (n % 5 == 0)
    {
        if (!fine[n - 42])
        {
            fine[n - 42] = true;
            if (bears(n - 42))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter the number of bears you want to check: ";
    cin >> n;
    if (bears(n))
    {
        cout << "You have reached the goal!";
    }
    else
        cout << "Cannot reach the goal!";
}