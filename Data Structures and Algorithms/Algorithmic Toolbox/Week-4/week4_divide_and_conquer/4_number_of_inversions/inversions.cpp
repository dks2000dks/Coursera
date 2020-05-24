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

void Print_Vector(vector<int> &array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

long long MergeVectors_get_inversions(vector<int> &a, vector<int> &b, int left, int ave, int right)
{
	int i = left;
	int j = ave+1;
	int count=0;

	for (int k=left;k<=right;k++)
	{
		if (i<=ave && j<=right)
		{
			if (a[i] <= a[j])
			{
				b[k] = a[i];
				i++;
			}
			
			else
			{
				count += ave-i+1;
				//cout << count << endl;
				b[k] = a[j];
				j++;
			}
		}

		else if (i>ave && j <= right)
		{
			b[k] = a[j];
			j++;
		}

		else if (i<=ave && j>right)
		{
			b[k] = a[i];
			i++;
		}
	}

	for (int i=left;i<=right;i++)
	{
		a[i] = b[i];
	}

	//Print_Vector(a,a.size());

	return count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right)
{
  long long number_of_inversions = 0;

  if (right <= left) return number_of_inversions;
  int ave = left + ((right - left) / 2);

  number_of_inversions += get_number_of_inversions(a, b, left, ave);
/*
  cout << left << " " << ave << endl;
  cout << number_of_inversions << endl;
  cout << "------------------" << endl;
*/
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
/*
  cout << ave+1 << " " << right << endl;
  cout << number_of_inversions << endl;
  cout << "------------------" << endl;
*/
  number_of_inversions += MergeVectors_get_inversions(a, b, left, ave, right);
/*
  cout << left << " " << right << endl;
  cout << number_of_inversions << endl;
  cout << "------------------" << endl;
*/
  return number_of_inversions;
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
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, (a.size()-1)) << endl;
}
