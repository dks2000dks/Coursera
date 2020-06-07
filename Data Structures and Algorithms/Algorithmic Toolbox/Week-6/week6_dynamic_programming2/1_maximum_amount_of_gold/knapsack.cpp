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

int optimal_weight(int W, const vector<int> &w){
    vector<vector<int>> dp(W+1,vector<int>(w.size()+1,0));
    fr(i,1,W){
        fr(j,1,w.size()){
            if (i-w[j-1] >= 0)
                dp[i][j] = max(dp[i][j-1],w[j-1] + dp[i-w[j-1]][j-1]);
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    return dp[W][w.size()];
}

int main(){
    int n, W;
    cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    cout << optimal_weight(W, w) << endl;
}
