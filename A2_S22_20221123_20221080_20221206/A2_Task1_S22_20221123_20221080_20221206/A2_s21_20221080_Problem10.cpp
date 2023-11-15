// File: Problem10.cpp
// Purpose: Message Altering to Avoid Censorship.
// Author:Sherif_mahmoud
// Section: s21
// ID: 20221080
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
wstring avoidCensorship(const wstring &text, const map<wstring, vector<wstring>> &lookupTable)
{
    wstring result = text;
    for (const auto &entry : lookupTable)
    {
        size_t found = result.find(entry.first);
        while (found != wstring::npos)
        {
            // Randomly select one alternative
            if (!entry.second.empty())
            {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<size_t> dist(0, entry.second.size() - 1);
                wstring replacement = entry.second[dist(gen)];

                result.replace(found, entry.first.length(), replacement);
            }
            found = result.find(entry.first, found + entry.first.length());
        }
    }
    return result;
}
int main()
{
    vector<wstring> Stand;  
    map<wstring, vector<wstring>> lookUpTable;
    cout << "Please enter the file name you want to uncensor: ";
    string filename, tableName;
    cin >> filename;
    cout << "Please enter the file name that has the alternatives words: ";
    cin >> tableName;
    wifstream file(filename);
    wifstream file2(tableName);

    if (!file.is_open() || !file2.is_open())
    {
        cout << "File not found" << endl;
        return 1;
    }

    // Read the contents of the first file into the 'Stand' vector
    wstring line;
    while (getline(file, line))
    {
        Stand.push_back(line);
    }

    // Read the contents of the second file into the 'lookUpTable' map
    wstring key, values;
    wstring line2;
    wstring delimiter = L"=";
    while (getline(file2, line2))
    {
        size_t pos = line2.find(delimiter);
        if (pos != wstring::npos)
        {
            key = line2.substr(0, pos);
            values = line2.substr(pos + 1);
            // Split the values into a vector
            wstringstream ss(values);
            wstring value;
            vector<wstring> alternatives;
            while (getline(ss, value, L','))
            {
                alternatives.push_back(value);
            }
            lookUpTable[key] = alternatives;
        }
    }
    // Close the original file
    file.close();
    // Open the original file for writing (truncates the file)
    wofstream outputFile(filename, ios::out | ios::trunc);
    if (!outputFile.is_open())
    {
        cout << "File not found" << endl;
        return 1;
    }
    // Modify and write the modified text back to the input file
    for (wstring &text : Stand)
    {
        outputFile << avoidCensorship(text, lookUpTable) << endl;
    }

    return 0;
}