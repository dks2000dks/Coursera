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
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

class StackWithMax {
    vector<int> stack;
    vector<int> trackstack;

  public:

    void Push(int value) {
        stack.push_back(value);
        if (stack.size()==1)
            trackstack.push_back(value);
        else{
            if (value > trackstack[trackstack.size()-1])
                trackstack.push_back(value);
            else
                trackstack.push_back(trackstack[trackstack.size()-1]);
        }
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
        trackstack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return trackstack[trackstack.size()-1];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}