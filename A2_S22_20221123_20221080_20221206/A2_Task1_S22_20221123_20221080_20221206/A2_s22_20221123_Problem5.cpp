// File: Problem_5.cpp
// Purpose: Scoreboard_screen
// Author: Mohamed_Taha
// Section: s22
// ID: 20221123
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, string>> v;
    cout << "- press 1 to add new high score: \n"
         << "- press 2 to print top ten scores: \n"
         << "- press 3 to print the highest score of a player: \n"
         << "- Press 0 to exit: \n";
    while (true)
    {
        cout << "  Select Your choice: ";
        int n;
        cin >> n;
        if (n == 1)
        {
            string x;
            int y;
            cout << "  Enter your name: ";
            cin >> x;
            cout << "  Enter your new score: ";
            cin >> y;
            v.push_back({y, x});
            sort(v.begin(), v.end(), greater<pair<int, string>>());
        }
        else if (n == 2)
        {
            if (!v.empty())
            {
                cout << "  The new top ten list is :- \n";
                for (int i = 0; i < v.size() && i < 10; i++)
                {
                    cout << i + 1 << "- " << v[i].second << " " << v[i].first << '\n';
                }
            }
        }
        else if (n == 3)
        {
            string name;
            cout << "Enter your name: ";
            cin >> name;
            bool found = false;
            for (int i = 0; i < v.size() && i < 10; i++)
            {
                if (v[i].second == name)
                {
                    cout << "- " << v[i].second << "'s highest score is: " << v[i].first << '\n';
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "- " << name << " is not in the top ten list. \n";
            }
        }
        else if (n == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid choice, Try again. \n";
        }
    }
}