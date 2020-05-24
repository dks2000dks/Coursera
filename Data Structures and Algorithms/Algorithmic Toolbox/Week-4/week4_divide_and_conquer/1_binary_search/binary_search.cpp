#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &a, int x)
{
  int left = 0, right = (int)a.size() - 1;

  while (left <= right)
  {
    int index = (left+right)/2;

    if (a[index] == x)
    {
      return index;
    }

    else if (a[index] > x)
    {
      right = index-1;
    }

    else
    {
      left = index+1;
    }
  }

  return -1;
  
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x) return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);

  for (size_t i = 0; i < a.size(); i++) 
  {
    std::cin >> a[i];
  }

  int m;
  std::cin >> m;
  vector<int> b(m);

  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i)
  {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }

  cout << endl;
}