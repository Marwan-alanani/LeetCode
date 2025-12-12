#include <bits/stdc++.h>

#include <string>
using namespace std;
class Solution {
 public:
  bool isPalindrome(int x) {
    string y = to_string(x);
    int i = 0, j = y.size() - 1;
    while (i < j) {
      if (y[i] != y[j]) return false;
      i++;
      j--;
    }
    return true;
  }
};

int main() {
  int x;
  cin >> x;
  string ans = Solution().isPalindrome(x) ? "True" : "False";
  cout<<ans<<endl;

  cout << endl;
}
