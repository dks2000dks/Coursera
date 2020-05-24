#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

struct results
{ 
    int start, end; 
};

typedef struct results Struct;

int partition2(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] <= x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void Print_Vector(vector<int> &array, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }

  cout << endl;
}

Struct partition3(vector<int> &a, int l, int r)
{
  Struct s;
  int x = a[l];
  int j = l;

  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] <= x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }

  swap(a[l], a[j]);

  int k = j;
  for (int i=j-1;i>=l;i--)
  {
    if (a[i] == a[j])
    {
      k--;
      swap(a[k],a[i]);
    }
  }

  s.start = k;
  s.end = j;

  return s;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  Struct s = partition3(a, l, r);

  randomized_quick_sort(a, l, s.start - 1);
  randomized_quick_sort(a, s.end + 1, r);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }

  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }

  cout << endl;
}
