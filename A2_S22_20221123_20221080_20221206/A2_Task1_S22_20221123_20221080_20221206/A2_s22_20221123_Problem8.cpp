// File: Problem8.cpp
// Purpose: A Fractal Pattern.
// Author: Mohamed_Taha
// Section: s22
// ID: 20221123
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
static void pattern(int n, int i)
{
    if (n == 1)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        cout << "*\n";
    }
    else
    {
        pattern(n / 2, i);
        for (int j = 0; j < i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << "\n";
        pattern(n / 2, i + n / 2);
    }
}
int main()
{
    int n, i;
    cin >> n >> i;
    pattern(n, i);
    return 0;
}