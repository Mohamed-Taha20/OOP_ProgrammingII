// File: Problem11.cpp
// Purpose: File Comparison.
// Author: Mohamed_Taha
// Section: s22
// ID: 20221123
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> check_word;
    vector<string> check_char;
    cout << "please enter the two file names that you want to compare: ";
    string filename, filename_;
    cin >> filename >> filename_;
    ifstream file(filename), file2(filename_);
    if (!file.is_open() || !file2.is_open())
    {
        cerr << "File not found" << endl;
        return 1;
    }
    string method;
    cout << "please enter words if you want ot compare word by word or characters if you want to compare character by character: ";
    cin >> method;
    bool identical = true;
    char ch, ch2;
    int count_word_file = 0, count_word_file2 = 0, count_char_file = 0, count_char_file2 = 0;
    while (file.get(ch))
    {
        if (ch == ' ' || ch == '.' || ch == '\n')
        {
            count_word_file++;
        }
        count_char_file++;
    }
    while (file2.get(ch2))
    {
        if (ch2 == ' ' || ch2 == '.' || ch2 == '\n')
        {
            count_word_file2++;
        }
        count_char_file2++;
    }
    file.clear();
    file2.clear();
    file.seekg(0);
    file2.seekg(0);
    if (method == "words")
    {
        int line = 1;
        char word;
        string words = "";
        if (count_word_file >= count_word_file2)
        {
            while (file2.get(word))
            {
                if (word == ' ' || word == '.' || word == '\n')
                {
                    if (words != "")
                    {
                        check_word.push_back(words);
                        words = "";
                    }
                }
                else
                {
                    words += word;
                }
            }
            while (file.get(word))
            {
                if (word == ' ' || word == '.' || word == '\n')
                {
                    if (find(check_word.begin(), check_word.end(), words) != check_word.end())
                    {
                        words = "";
                    }
                    else
                    {
                        identical = false;
                        cout << "the first different word is -> " << words << "\tthe line is -> " << line << "\tthe file i compare with is -> " << filename_ << endl;
                        words = "";
                    }
                }
                else
                {
                    words += word;
                }
                if (word == '\n')
                {
                    line++;
                }
            }
            if (identical)
            {
                cout << "Identical" << endl;
            }
        }
        else
        {
            while (file.get(word))
            {
                if (word == ' ' || word == '.' || word == '\n')
                {
                    if (words != "")
                    {
                        check_word.push_back(words);
                        words = "";
                    }
                }
                else
                {
                    words += word;
                }
            }
            while (file2.get(word))
            {
                if (word == ' ' || word == '.' || word == '\n')
                {
                    if (find(check_word.begin(), check_word.end(), words) != check_word.end())
                    {
                        words = "";
                    }
                    else
                    {
                        identical = false;
                        cout << "the first different word is -> " << words << "\tthe line is -> " << line << "\tthe file i compare with  is -> " << filename << endl;
                        words = "";
                    }
                }
                else
                {
                    words += word;
                }
                if (word == '\n')
                {
                    line++;
                }
            }
            if (identical)
            {
                cout << "Identical" << endl;
            }
        }
    }
    else if (method == "characters")
    {
        int line = 0;
        char word;
        string wordc;
        if (count_char_file >= count_char_file2)
        {
            while (getline(file2, wordc))
            {
                check_char.push_back(wordc);
            }
            int i = 0, j = 0;
            while (file.get(word))
            {
                if (word == check_char[i][j])
                {
                    j++;
                }
                else if (word != '\n')
                {
                    identical = false;
                    cout << "the first line that is different -> " << check_char[i] << " the line is -> " << i + 1 << "\tthe file i compare with is -> " << filename_ << endl;
                }
                if (word == '\n')
                {
                    i++;
                    j = 0;
                }
            }
            if (identical)
            {
                cout << "Identical" << endl;
            }
        }
        else
        {
            while (getline(file, wordc))
            {
                check_char.push_back(wordc);
            }
            int i = 0, j = 0;
            while (file2.get(word))
            {
                if (word == check_char[i][j])
                {
                    j++;
                }
                else if (word != '\n')
                {
                    identical = false;
                    cout << "the first line that is different -> " << check_char[i] << " the line is -> " << i + 1 << "\tthe file i compare with is -> " << filename << endl;
                }
                if (word == '\n')
                {
                    i++;
                    j = 0;
                }
            }
            if (identical)
            {
                cout << "Identical" << endl;
            }
        }
    }
}