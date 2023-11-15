// File: Problem7.cpp
// Purpose: The game of dominos.
// Author: Sherif_mahmoud
// Section: s21
// ID: 20221080
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
struct dominoT
{
    int leftDots;
    int rightDots;
};
// a function to check whether the given domonos can be made a chain or not
// this loops over each left dots and searches for the corresponding right dots
// if such a merge found then mark them by -1
// i is the index of the left dot and j is the index of the right dot
// search for dominos[i] by j
void check(vector<dominoT> &dominos, int i, int j)
{
    if (i == dominos.size())
    {
        return;
    }
    if (j == dominos.size())
    {
        check(dominos, i + 1, 0);
        return;
    }

    if (dominos[i].leftDots == dominos[j].rightDots)
    {
        dominos[i].leftDots = -1;
        dominos[j].rightDots = -1;
    }

    check(dominos, i, j + 1);
}
void check(vector<dominoT> &dominos)
{
    check(dominos, 0, 0);
}
bool FormsDominoChain(const vector<dominoT> &dominos)
{
    int count_left = 0, count_right = 0;
    for (int i = 0; i < dominos.size(); i++)
    {
        if (dominos[i].leftDots != -1)
        {
            count_left++;
        }
        if (dominos[i].rightDots != -1)
        {
            count_right++;
        }
    }
    return (count_left <= 1 && count_right <= 1);
}
// checking each permutation given by the next permutation function
bool isValidChain(const vector<pair<int, int>> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].second != v[i + 1].first)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "enter the number of dominos: ";
    cin >> n;
    vector<dominoT> domos(n);
    vector<pair<int, int>> v; // a copy of the dominos vector because of the -1 mark in the check function
    cout << "enter each domino the left dots then the right dots: ";
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        domos[i].leftDots = x;
        domos[i].rightDots = y;
        v.push_back({domos[i].leftDots, domos[i].rightDots});
    }

    sort(v.begin(), v.end());

    check(domos);

    if (FormsDominoChain(domos))
    {
        bool f = false;
        do
        {
            if (isValidChain(v))
            {
                f = true;
                break;
            }
        } while (next_permutation(v.begin(), v.end())); // to print the required permutation

        if (f)
        {
            cout << "The chain is: ";
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)
                {
                    cout << v[i].first << "|" << v[i].second << " ";
                }
                else
                {
                    cout << v[i].first << "|" << v[i].second << " - ";
                }
            }
        }
        else
        {
            cout << "There is no way to form a domino chain.\n";
        }
    }
    else
    {
        cout << "There is no way to form a domino chain.\n";
    }
    return 0;
}