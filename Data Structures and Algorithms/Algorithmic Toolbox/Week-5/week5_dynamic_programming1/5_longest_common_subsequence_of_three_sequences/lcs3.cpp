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

void Print_Vector(vector<int> &array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int l = a.size();
    int m = b.size();
    int n = c.size();

    int table[l+1][m+1][n+1];

    fr(i,0,l){
        fr(j,0,m){
            fr(k,0,n){
                if (i==0 || j==0 || k==0)
                    table[i][j][k] = 0;
                else if (a[i-1] == b[j-1] && c[k-1] == a[i-1])
                    table[i][j][k] = table[i-1][j-1][k-1] + 1;
                else
                    table[i][j][k] = max(max(table[i-1][j][k],table[i][j-1][k]),table[i][j][k-1]);
            }
        }
    }

    return table[l][m][n];
}

int main(){
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }

    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }

    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }

    std::cout << lcs3(a, b, c) << std::endl;
}
