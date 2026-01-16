#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int l = 0;
    int n = haystack.size();
    int m = needle.size();
    while (l + m - 1 < n) {
      int r = l;
      while (r < n && r - l < m && haystack[r] == needle[r - l]) {
        r++;
      }
      if (r - l == m) {
        return l;
      }
      l++;
    }
    return -1;
  }
};

int main() {
  string needle=  "leeto";
  string haystack=  "leetcode";
  cout<< Solution().strStr(haystack, needle)<<endl;;
}
