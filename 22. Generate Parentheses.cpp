#include <bits/stdc++.h>

#include <deque>
#include <vector>
using namespace std;
class Solution {
 public:
  deque<char> seq;
  int countOp;
  int countCl;
  int n;
  vector<string> ans = vector<string>();
  vector<string> generateParenthesis(int n) {
    this->n = n;
    generate();
    return ans;
  }
  void generate() {
    if (seq.size() == 2 * n) return addToAns();
    if (countOp == 0 || countCl == countOp) return tryOpen();
    if (countOp == n) return tryClose();
    tryClose();
    tryOpen();
  }

  void tryClose() {
    seq.push_back(')');
    countCl++;
    generate();
    seq.pop_back();
    countCl--;
  }

  void tryOpen() {
    seq.push_back('(');
    countOp++;
    generate();
    seq.pop_back();
    countOp--;
  }

  void addToAns() {
    string one = "";
    for (auto& el : seq) one += el;
    ans.push_back(one);
  }
};

int main() {
  auto ans = Solution().generateParenthesis(2);
  for (auto& st : ans) {
    cout << st << endl;
  }
}
