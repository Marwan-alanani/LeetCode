#include <bits/stdc++.h>

using namespace std;
class Solution {
  int m, n;

 public:
  int minPathSum(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<int>> dyn =
        vector<vector<int>>(m + 1, vector<int>(n + 1, 201));
    dyn[1][1] = grid[0][0];
    for (int i = 1; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (1 == i && 1 == j) continue;
        dyn[i][j] = min(dyn[i - 1][j], dyn[i][j - 1]) + grid[i - 1][j - 1];
      }
    }
    return dyn[m][n];
  }
};

int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << Solution().minPathSum(grid) << endl;
}
