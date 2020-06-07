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
#define fr(i, a, b) for (ll i=a; i<=b; i++)

void Print_Vector(vector<ll> &array, ll size){
    for (ll i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

long long eval(long long a, long long b, char op){
    if (op == '*')
        return a * b;
    else if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else
        assert(0);
}

struct result{
    ll minimum, maximum; 
};

typedef struct result Struct;

Struct MinAndMax(const string &exp, vector<vector<ll>> &Max, vector<vector<ll>> &Min, ll i, ll j, vector<char> &operations){
    ll m = LONG_MAX;
    ll M = LONG_MIN;
    Struct s;

    fr(k,i,j-1){
        char op = operations[k];
        ll a = eval(Max[i][k], Max[k+1][j], op);
        ll b = eval(Max[i][k], Min[k+1][j], op);
        ll c = eval(Min[i][k], Max[k+1][j], op);
        ll d = eval(Min[i][k], Min[k+1][j], op);

        m = min(min(min(a,b),min(c,d)),m);
        M = max(max(max(a,b),max(c,d)),M);
    }
    s.maximum = M;
    s.minimum = m;
    return s;
}

long long get_maximum_value(const string &exp) {
    ll m = exp.length();
    ll n = (m+1)/2;

    vector<ll> numbers(n);
    vector<char> operations(n-1);
    fr(i,0,m-1){
        if (i%2==0)
            numbers[i/2] = std::stoi(&exp[i]);
        else
            operations[i/2] = exp[i];
    }

    vector<vector<ll>> Max(n,vector<ll> (n,0));
    vector<vector<ll>> Min(n,vector<ll> (n,0));
    Struct s;

    fr(i,0,n-1){
        fr(j,0,n-1){
            if (i==j){
                Max[i][j] = numbers[i];
                Min[i][j] = numbers[i];
            }
        }
    }

    fr(l,1,n-1){
        fr(i,0,n-l-1){
            ll j = i+l;
            s = MinAndMax(exp,Max,Min,i,j,operations);
            Min[i][j] = s.minimum;
            Max[i][j] = s.maximum;
        }
    }
    return Max[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
