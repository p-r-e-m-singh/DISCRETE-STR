#include <bits/stdc++.h>
using namespace std;
// Function to calculate
// leaf nodes in n-ary tree
int calcNodes(int M, int I) {
  int result = 0;
  result = I * (M - 1) + 1;
  return result;
}

int main() {
  int M, I;
  cout << "enter the values of M : ";
  cin >> M;
  cout << "enter the values of I : ";
  cin >> I;
  cout << "Leaf nodes = " << calcNodes(M, I);
  return 0;
}
