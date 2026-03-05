#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<string> ans = vector<string>();
  map<char, vector<char>> m;
  vector<char> cur;

  void init() {
    m['2'] = {'a', 'b', 'c'};
    m['3'] = {'d', 'e', 'f'};
    m['4'] = {'g', 'h', 'i'};
    m['5'] = {'j', 'k', 'l'};
    m['6'] = {'m', 'n', 'o'};
    m['7'] = {'p', 'q', 'r', 's'};
    m['8'] = {'t', 'u', 'v'};
    m['9'] = {'w', 'x', 'y', 'z'};
  }

  vector<string> letterCombinations(string digits) {
    if (m.size() == 0) {
      init();
    }
    generate(digits);
    return ans;
  }
  void generate(string& digits, int idx = 0) {
    if (idx == digits.size()) {
      string nw = "";
      for (auto& lett : cur) {
        nw += lett;
      }
      ans.push_back(nw);
      return;
    };
    char curDig = digits[idx];
    for (auto& lett : m[curDig]) {
      cur.push_back(lett);
      generate(digits, idx + 1);
      cur.pop_back();
    }
  }
};
int main() {
  vector<string> ans = Solution().letterCombinations("23");
  for (auto& st : ans) {
    cout << st << endl;
  }
}
