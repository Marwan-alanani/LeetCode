#include <bits/stdc++.h>

#include <string>
using namespace std;
class Solution {
 public:
  string countAndSayStr = "1";
  int n;
  string countAndSay(int n) {
    this->n = n;
    return recur(1);
  }

  string recur(int m) {
    if (m == n) return countAndSayStr;
    countAndSayStr = compress(countAndSayStr);
    return recur(m + 1);
  }

  string compress(string s) {
    int i = 0;
    int n = s.size();
    string ans = "";
    while (i < n) {
      int count = 0;
      char cur = s[i];
      while (i < n && s[i] == cur) {
        i++;
        count++;
      }
      ans += to_string(count);
      ans += cur;
    }
    return ans;
  }
};
