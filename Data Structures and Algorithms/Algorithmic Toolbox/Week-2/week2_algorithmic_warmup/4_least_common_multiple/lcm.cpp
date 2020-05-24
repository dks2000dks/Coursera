#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long lcm_naive(int a, int b) 
{
	for (long l = max(a,b); l <= (long long) a * b; ++l)
		if (l % a == 0 && l % b == 0)
			return l;

	return (long long) a * b;
}

long long int gcdrecursive(long long int a, long long int b)
{
  // Eucliden GCD
  if (b==0)
    return a;

  return gcdrecursive(b,a%b);
}

long long int lcm_fast(int a, int b)
{
	int g = gcdrecursive(a,b);
	long long int l = ((long long int)a*b);
	return l/g;
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
