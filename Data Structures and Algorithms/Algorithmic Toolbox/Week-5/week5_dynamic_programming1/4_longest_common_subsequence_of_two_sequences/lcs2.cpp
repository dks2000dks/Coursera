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

int lcs2(vector<int> &X, vector<int> &Y) {
    int m = X.size();
    int n = Y.size();

    int table[m+1][n+1];

    fr(i,0,m)
    {
        fr(j,0,n)
        {
            if (i==0 || j==0)
                table[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                table[i][j] = table[i-1][j-1] + 1;
            else
                table[i][j] = max(table[i-1][j],table[i][j-1]);
        }
    }

    return table[m][n];
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++){
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    std::cout << lcs2(a, b) << std::endl;
}
