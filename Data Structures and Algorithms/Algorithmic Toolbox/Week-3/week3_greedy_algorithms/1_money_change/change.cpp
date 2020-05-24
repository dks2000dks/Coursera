#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int get_change(int m)
{
	int x = m/10;
	m = m-10*x;

	int y = m/5;
	m = m-y*5;

	int z = m/1;

	int n = x+y+z;
	return n;
}

int main()
{
	int m;
	std::cin >> m;
	std::cout << get_change(m) << endl;;
}
