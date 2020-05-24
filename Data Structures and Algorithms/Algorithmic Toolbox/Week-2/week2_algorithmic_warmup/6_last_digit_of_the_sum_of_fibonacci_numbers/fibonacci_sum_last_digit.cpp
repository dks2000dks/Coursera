#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0%10;
    long long current  = 1%10;
    long long sum      = 1%10;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%10;
        previous = current%10;
        current = (tmp_previous + current)%10;
        sum += current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n%60) << endl;
}
