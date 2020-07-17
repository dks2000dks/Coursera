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
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

struct Node{
  int key, left, right;
};

class Tree{
  int n;
  vector<Node> node;

public:
  void Data(){
    cin >> n;
    node.resize(n);
    for (int i = 0; i < n; i++)
    {
      cin >> node[i].key >> node[i].left >> node[i].right;
    }
  }

  void preOrder(int index){
    if (index != -1){
      cout << node[index].key << ' ';
      preOrder(node[index].left);
      preOrder(node[index].right);
    }
  }

  void postOrder(int index){
    if (index != -1){
      postOrder(node[index].left);
      postOrder(node[index].right);
      cout << node[index].key << ' ';
    }
  }

  void inOrder(int index){
    if (index != -1){
      inOrder(node[index].left);
      cout << node[index].key << ' ';
      inOrder(node[index].right);
    }
  }
};


int main(){
  Tree t;
  t.Data();

  t.inOrder(0);
  cout << endl;
  t.preOrder(0);
  cout << endl;
  t.postOrder(0);
  cout << endl;
  return 0;
}