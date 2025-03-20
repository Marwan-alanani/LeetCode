#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int bestS = 0;
    int mx = INT_MIN;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (ok(s, i, j)) {
          if (j - i + 1 > mx) {
            mx = j - i + 1;
            bestS = i;
          }
        }
      }
    }
    return s.substr(bestS, mx);
  }

  bool ok(string& s, int& st, int& en) {
    int i = st;
    int j = en;
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
};

