#include <iostream>
#include <vector>
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0%10;
    long long next  = 1%10;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current%10;
        }

        long long new_current = next%10;
        next = (next + current)%10;
        current = new_current%10;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    int p = from%60;
    int q = to%60;

    if (q>=p)
    {
        cout << get_fibonacci_partial_sum_naive(p, q)%10 << endl;
    }

    else
    {
        int out = get_fibonacci_partial_sum_naive(0, 59) - get_fibonacci_partial_sum_naive(q+1, p-1)%10;

        if (out < 0)
            cout << 10+out << endl;
        else
            cout << out << endl;
    }
}
