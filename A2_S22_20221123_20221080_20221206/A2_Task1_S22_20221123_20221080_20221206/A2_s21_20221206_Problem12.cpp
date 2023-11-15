// File: Problem12_.cpp
// Purpose: Phishing Scanner.
// Author: Youssif_waleed
// Section: s21
// ID: 20221206
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
// a function that counts the number of occurrences for a sting in a file
int count_occurrences(string fileName, string str)
{
    fstream file(fileName);
    string line;
    int count = 0;

    while (getline(file, line))
    {
        int pos = line.find(str); // storing the position of the first occurrence of the search string in the current line of the file.
        while (pos != string::npos)
        {
            count++;
            pos = line.find(str, pos + str.length());
        }
    }
    file.close();
    return count;
}
int main()
{
    // A list of 30 common words used in phishing scams
    string top_phishing_scams[30] = {"Phishing", "Spoofing", "Account Verification", "Password Reset", "Security Alert",
                                     "Suspicious Activity", "Unauthorized Access", "Update Your Information", "Limited Time Offer", "Free Gift", "Account Suspension",
                                     "Unusual Login Attempt", "Verify Your Identity", "Confirm Your Account", "Important Notification", "Financial Institution",
                                     "Tax Refund", "Lottery Winner", "Prize Claim", "Fake Invoice", "Urgent Action Required", "Confidential Information",
                                     "Data Breach", "Phishing Link", "Account Compromise", "Account Expiration", "Payment Confirmation", "Email Account Update",
                                     "Account Closure Notice"};
    map<string, int> num_of_occurrences;
    vector<int> points(30);
    string filename;
    ifstream file(filename);
    cout << "Please enter the file name: ";
    cin >> filename;
    // filling the points for each string in the list
    for (int i = 0; i < 30; i++)
    {
        points[i] = (i % 3) + 1;
    }
    for (int i = 0; i < 29; i++)
    {
        // linking each string with the number of occurrences in the file
        num_of_occurrences[top_phishing_scams[i]] = count_occurrences(filename, top_phishing_scams[i]);
    }
    // itrate over each word to print its status
    auto it = num_of_occurrences.begin();
    int sum = 0;
    int i = 0;
    while (it != num_of_occurrences.end())
    {
        cout << "the number of occurrences of "
             << '"' << it->first << '"' << " is :" << it->second << endl;
        cout << "the total point of this word is "
             << (it->second * points[i]) << endl;
        sum += (it->second * points[i]);
        it++;
        i++;
    }
    cout << "the total number of points in the entire file is : " << sum << endl;
    return 0;
}