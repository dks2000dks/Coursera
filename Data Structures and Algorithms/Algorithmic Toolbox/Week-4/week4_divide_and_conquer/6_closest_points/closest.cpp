#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i, a, b) for (int i=a; i<=b; i++)


// Print Vector Pair
void Print_Vector(vector<pair<int,int>> &array)
{
  for (int i = 0; i < array.size(); i++)
  {
    cout << array[i].first << " ";
  }

  cout << endl;

  for (int i = 0; i < array.size(); i++)
  {
    cout << array[i].second << " ";
  }

  cout << endl;
}


// Calculating Euclidian Distance
double euclidiandistance(int x1,int x2, int y1, int y2)
{
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}


// Sort by Second Element
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
  return (a.second < b.second);
}


// Calculating Minimal Distance
double minimal_distance(vector <pair<int,int>> &points, vector <pair<int,int>> &pointsy, int left, int right)
{
  int size = (-left+right);
  int m;
  double ref,d;

  if (left+1==right)
  {
    return euclidiandistance(points[left].first, points[right].first, points[left].second, points[right].second); 
  }

  else if (left==right)
  {
    return DBL_MAX;
  }

  m = left + (size/2);
  ref = points[m].first;
  
  double d1 = minimal_distance(points,pointsy,left,m);
  double d2 = minimal_distance(points,pointsy,m+1,right);

  d = min(d1,d2);

  std::vector<pair<int,int>> strip;
  for (int i=0;i<pointsy.size();i++)
  {
    if (abs(pointsy[i].first - ref) < d)
    {
      strip.push_back(pointsy[i]);
    }
  }

  if (strip.size() > 0)
  {
    for (int p=0; p<strip.size()-1; p++)
    {
      for (int q=p+1; q<strip.size() && abs(p-q) < 7; q++)
      {
        if (abs(strip[p].second - strip[q].second) < d)
        {
          double md = euclidiandistance(strip[p].first,strip[q].first,strip[p].second,strip[q].second);
          d = min(d,md);
        }

        else
          break;
      }
    }
  }

  return d;
}

int main()
{
  size_t n;
  std::cin >> n;
  int x,y;

  vector < pair<int,int> > points,pointsy;

  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x >> y;
    points.push_back(make_pair(x,y));
    pointsy.push_back(make_pair(x,y));
  }

  sort (points.begin(),points.end());
  sort (pointsy.begin(),pointsy.end(),sortbysec);

  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points,pointsy,0,points.size()-1) << endl;
}
