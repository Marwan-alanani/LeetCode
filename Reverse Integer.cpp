#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    bool negative = false;
    if (x < 0) {
      negative = true;
    }
    string mxP = to_string(INT32_MAX);
    string mxN = to_string(INT32_MIN);
    mxN = mxN.substr(1);

    string digits = to_string(x);

    if (negative)
      digits = digits.substr(1);

    if (digits.size() < mxN.size())
      return toReversedInt(digits, negative);

    int i = 0;
    string comparer;
    if (negative)
      comparer = mxN;
    else
      comparer = mxP;

    while (comparer[i] == digits[digits.size() - 1 - i])
      i++;

    if (digits[digits.size() - 1 -i] > comparer[i])
      return 0;
    return toReversedInt(digits, negative);
  }

  int toReversedInt(string x, bool neg) {
    int mult = 1;
    int ans = 0;
    for (int i = 0; i < x.size(); i++) {
      int num = x[i] - '0';
      ans += num * mult;
      if(i < 9) mult *= 10;
    }
    if (neg)
      return ans * -1;
    return ans;
  }
};

int main() {
  int x;
  cin >> x;
  cout << Solution().reverse(x);
}
