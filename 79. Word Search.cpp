#include <bits/stdc++.h>

#include <vector>
using namespace std;
class Solution {
 public:
  int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  string word;
  vector<vector<bool>> vis;
  int n, m;
  vector<vector<char>> board;
  int idx = 0;

  bool exist(vector<vector<char>>& board, string word) {
    this->board = board;
    this->word = word;
    this->n = board.size();
    this->m = board[0].size();
    this->vis = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[idx]) {
          if (dfs(i, j)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  bool dfs(int r, int c) {
    idx++;
    if (idx == word.size()) return true;
    vis[r][c] = true;
    for (auto& [dr, dc] : dir) {
      int row = r + dr;
      int col = c + dc;
      if (valid(row, col) && !vis[row][col] && board[row][col] == word[idx]) {
        if (dfs(row, col)) return true;
      }
    }

    vis[r][c] = false;
    idx--;
    return false;
  }

  bool valid(int r, int c) { return r > -1 && r < n && c > -1 && c < m; }
};

int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};

  string word = "ABCESEEEFS";
  if (Solution().exist(board, word)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}
