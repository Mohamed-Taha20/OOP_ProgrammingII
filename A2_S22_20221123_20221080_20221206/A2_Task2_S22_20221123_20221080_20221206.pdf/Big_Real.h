#ifndef UNTITLED6_BIG_REAL_H
#define UNTITLED6_BIG_REAL_H
#include <bits/stdc++.h>
using namespace std;
class BigReal {
private:
    string number;
    bool isValidReal(string s);
    bool index=false;
public:
    BigReal();
    BigReal(string s);
    BigReal operator+ (BigReal num2);
    BigReal operator- (BigReal num2);
    bool operator< (BigReal num2);
    bool operator> (BigReal num2);
    bool operator== (BigReal num2);
    friend ostream& operator<<(ostream& out, BigReal num);
};

#endif //UNTITLED6_BIG_REAL_H
