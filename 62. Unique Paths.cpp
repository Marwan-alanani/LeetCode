#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
 public:
  int uniquePaths(int m, int n) {
    int N = m + n - 2;
    int r = min(m - 1, n - 1);

    ll ans = 1;

    for (int i = 1; i <= r; i++) {
      ans = ans * (N - r + i) / i;
    }

    return (int)ans;
  }
};

int main() { cout << Solution().uniquePaths(7, 3) << endl; }
