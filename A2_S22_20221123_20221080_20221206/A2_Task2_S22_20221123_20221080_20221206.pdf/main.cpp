// File: Task2.cpp
// Purpose: Bigreal program.
// Author(ID): Sherif_mahmoud(20221080)
// Author(ID): Mohamed_Taha(20221123)
// Author(ID): Youssif_Waleed(20221206)
// Section: s21
// TA: Rana Abdelkader
// Date: 5 Nov 2023
#include <bits/stdc++.h>
#include "Big_Real.h"
using namespace std;
int main()
{
    BigReal n1("11.9000000000000000000000000000000001");
    BigReal n2("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << n3;
}