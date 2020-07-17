#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h>
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define vec1d(v, T, n, init) vector<T> v(n, init)
#define vec2d(v, T, n, m, init) vector<vector<T>> v(n, vector<T>(m, init))

struct Node
{
    ll key, left, right;
};

class BT
{
    vector<Node> Positions;

public:
    ll data;
    BT *left, *right;

    void Data(ll n)
    {
        Positions.resize(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> Positions[i].key >> Positions[i].left >> Positions[i].right;
        }
    }

    BT()
    {
        data = 0;
        left = NULL;
        right = NULL;
    };

    void inOrder(BT *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    };

    BT *ConstructBT(BT *node, ll index)
    {
        if (index != -1)
        {
            node->data = Positions[index].key;
            if (Positions[index].left != -1){
                node->left  = new BT();
                node->left = ConstructBT(node->left, Positions[index].left);
            }

            if (Positions[index].right != -1){
                node->right  = new BT();
                node->right = ConstructBT(node->right, Positions[index].right);
            }
        }

        return node;
    }

    ll isBSTUntil(BT *node, ll min, ll max)
    {
        if (node == NULL)
            return 1;

        if (node->data < min || node->data > max)
            return 0;

        return (isBSTUntil(node->left, min, node->data - 1) && isBSTUntil(node->right, node->data, max));
    }
};

int main()
{
    ll n;
    cin >> n;
    if (n>0){
        BT bt;
        bt.Data(n);

        BT *root = new BT();
        root = bt.ConstructBT(root, 0);

        if (bt.isBSTUntil(root, LONG_MIN, LONG_MAX))
            cout << "CORRECT" << endl;

        else
            cout << "INCORRECT" << endl;
    }

    else{
        cout << "CORRECT" << endl;
    }

    return 0;
}
