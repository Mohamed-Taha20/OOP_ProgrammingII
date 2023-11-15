// File: Problem4.cpp
// Purpose: Primes_printer.
// Author: Sherif_mahmoud
// Section: s21
// ID: 20221080
// TA: Rana Abdelkader
// Date: 4 Nov 2023
#include <iostream>
using namespace std;
bool isPrime(int n)
{
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;

  return true;
}

int main()
{
  int n;
  cout << "Enter the number: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    if (isPrime(i))
      cout << i << " ";
  }

  return 0;
}