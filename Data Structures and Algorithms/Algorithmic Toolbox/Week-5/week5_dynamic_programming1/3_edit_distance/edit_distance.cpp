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
#include <math.h> 
#include <float.h>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)


using std::string;

int edit_distance(const string &str1, const string &str2){

	int m = str1.length();
	int n = str2.length();
	
	int table[m+1][n+1];

	fr(i,0,m){
		fr(j,0,n){
			if (i==0)
				table[i][j] = j;
			else if (j==0)
				table[i][j] = i;
			else if (str1[i-1] == str2[j-1])
				table[i][j] = table[i-1][j-1];
			else
				table[i][j] = 1 + min(min(table[i-1][j],table[i][j-1]),table[i-1][j-1]);
		}
	}

	return table[m][n];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
