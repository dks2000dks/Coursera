#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

int get_count(vector<int> &v, int left, int right, int key)
{
  if (key != -1)
  {
    int count=0;
    for (int i=left;i<right+1;i++)
    {
      if (v[i] == key)
        count++;
    }
    return count;
  }

  else
    return 0;  
}

int get_majority_element(vector<int> &a, int left, int right)
{
  if (left == right) return a[left];
  
  int m = (left+right)/2;

  int e = get_majority_element(a,left,m);
  int f = get_majority_element(a,m+1,right);

  if (e==f)
    return e;

  else
  {
    int p = get_count(a,left,right,e);
    int q = get_count(a,left,right,f);

    if (p>q && p>(right-left+1)/2)
      return e;
    else if (q>p  && q>(right-left+1)/2)
      return f;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);

  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }

  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
