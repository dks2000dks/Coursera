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

int get_change(int m) {
	if (m==1 || m==3 || m==4)
		return 1;
	else if (m==2)
		return 2;
	else if (m==0)
		return 0;
	else{
		std::vector<int> change(m+1,0);
		change[0] = 0;
		change[1] = 1;
		change[2] = 2;
		change[3] = 1;
		change[4] = 1;
		fr(i,5,m){
			change[i] = min(min(1+change[i-1],1+change[i-3]),1+change[i-4]);
		}
		return change[m];
	}
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << endl;
}
