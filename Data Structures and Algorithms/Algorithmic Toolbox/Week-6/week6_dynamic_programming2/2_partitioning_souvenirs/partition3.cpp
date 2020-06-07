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


int partition3(vector<int> &A) {
	int sum = accumulate(v.begin(), v.end(), 0);
	if (sum%3 != 0)
		return 0;
	else{
		int value = sum/3;
	}
}

int main() {
	int n;
	std::cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) {
    	cin >> A[i];
	}
	cout << partition3(A) << endl;
}
