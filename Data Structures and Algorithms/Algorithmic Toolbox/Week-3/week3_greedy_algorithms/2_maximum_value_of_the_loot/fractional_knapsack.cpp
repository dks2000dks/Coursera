#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

double get_optimal_value(double capacity, vector<double> weights, vector<double> values)
{
  vector<double> perweigh(weights.size());
  
  for (int i=0;i<values.size();i++)
  {
    perweigh[i] = values[i]/weights[i];
  }

  // Creating a Map between PerWeighs and Weights.
  map<double,double> weighmap;

  for (int i=0;i<perweigh.size();i++)
  {
    weighmap[perweigh[i]] = weights[i];
  }

  sort(perweigh.begin(),perweigh.end(),greater<double>());

  double totalvalue = 0.0;

  for (int i=0;i<perweigh.size();i++)
  {
    if (capacity==0)
      return totalvalue;

    double a = min(weighmap[perweigh[i]],capacity);

    totalvalue = totalvalue + perweigh[i]*a;
    capacity = capacity - a;

    weighmap[perweigh[i]] = weighmap[perweigh[i]] - a;
  }

  return totalvalue;
}

int main()
{
  int n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);

  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
