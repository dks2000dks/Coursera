#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long int get_fibonacci_huge_naive(long long int n, long long int m)
{
    if (n <= 1)
        return n;

    long long previous = 0%m;
    long long current  = 1%m;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%m;
        previous = current%m;
        current = (tmp_previous + current)%m;
    }

    return current % m;
}

long long int PisanoPeriod(long long int n, long long int m)
{
    int a = 0;
    int b = 1;
    int c,d;

    int i = 1;
    while(1)
    {
        i++;
        c = (a+b)%m;
        d = (c+b)%m;

        if (c==0 && d==1)
            return i;

        a = b;
        b = c;
    }
}

int main()
{
    long long int n, m;
    std::cin >> n >> m;

    long long int p = PisanoPeriod(n,m);

    std::cout << get_fibonacci_huge_naive(n%p, m) << '\n';
}
