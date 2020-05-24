#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long int gcdrecursive(long long int a, long long int b)
{
  // Eucliden GCD
  if (b==0)
    return a;

  return gcdrecursive(b,a%b);
}

int main()
{
  long long int a, b;
  std::cin >> a >> b;
  std::cout << gcdrecursive(a, b) << std::endl;
  return 0;
}
