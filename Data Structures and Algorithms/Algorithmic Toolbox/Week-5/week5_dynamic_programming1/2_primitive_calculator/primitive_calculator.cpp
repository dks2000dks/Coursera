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

vector<int> optimal_sequence(int n) {
    std::vector<int> f;
    if (n==1){
        f.push_back(1);
        return f;
    }
    else if (n==2){
        f.push_back(1);
        f.push_back(2);
        return f;
    }
    else if (n==3){
        f.push_back(1);
        f.push_back(3);
        return f;
    }
    else {
        vector<int> output;
        vector<int> f(n+1);
        f[0] = 0;
        f[1] = 1;
        f[2] = 2;
        f[3] = 2;
        fr(i,4,n){
            if (i%2 == 0 && i%3 ==0)
                f[i] = min(min(1+f[i/2],1+f[i/3]),1+f[i-1]);
            else if (i%2==0)
                f[i] = min(1+f[i/2],1+f[i-1]);
            else if (i%3==0)
                f[i] = min(1+f[i/3],1+f[i-1]);
            else
                f[i] = 1+f[i-1];
        }

        output.push_back(n);
        while(n>1){
            if (n%2==0 &&n%3==0){
                int mi = min(min(f[n/3],f[n/2]),f[n-1]);
                if (mi == f[n/3]){
                    output.push_back(n/3);
                    n = n/3;
                }
                else if (mi == f[n/2]){
                    output.push_back(n/2);
                    n = n/2;
                }
                else{
                    output.push_back(n-1);
                    n=n-1;
                }
            }

            else if (n%2 == 0){
                int mi = min(f[n/2],f[n-1]);
                if (mi == f[n/2]){
                    output.push_back(n/2);
                    n=n/2;
                }
                else{
                    output.push_back(n-1);
                    n=n-1;
                }
            }

            else if (n%3 == 0){
                int mi = min(f[n/3],f[n-1]);
                if (mi == f[n/3]){
                    output.push_back(n/3);
                    n=n/3;
                }
                else{
                    output.push_back(n-1);
                    n=n-1;
                }
            }

            else{
                output.push_back(n-1);
                n=n-1;
            }
        }
        reverse(output.begin(),output.end());
        return output;
    }
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    cout << sequence.size() - 1 << endl;
    Print_Vector(sequence,sequence.size());
}

