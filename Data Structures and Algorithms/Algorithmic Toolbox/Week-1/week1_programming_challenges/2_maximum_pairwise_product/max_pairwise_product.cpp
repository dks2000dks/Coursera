#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(vector<int>& numbers)
{

    sort(numbers.begin(), numbers.end(), greater<int>());

    long long max_product = (long long)(numbers[0]) * numbers[1];

    return max_product;
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << endl;
    return 0;
}
