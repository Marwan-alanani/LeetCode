#include <bits/stdc++.h>

#include <cstdint>
#include <cstdlib>
using namespace std;
#define ll long long
class Solution {
 public:
  int divide(int dividend, int divisor) {
    ll sub = divisor;
    ll rem = dividend;
    ll ans = 0;
    ll count = 1;
    while (rem != 0) {
      if (abs(rem) < abs((ll)divisor)) {
        break;
      }

      if (divisor < 0 && dividend < 0) {
        rem -= sub;
        ans += count;
      } else if (divisor > 0 && dividend > 0) {
        rem -= sub;
        ans += count;
      } else {
        rem += sub;
        ans -= count;
      }
      sub += sub;
      count += count;
      if (abs(sub) > abs(rem)) {
        sub = divisor;
        count = 1;
      }
    }
    if (ans > INT32_MAX) {
      return INT32_MAX;
    }
    if (ans < INT32_MIN) {
      return INT32_MIN;
    }

    return ans;
  }
};

int main() { cout << Solution().divide(-1010369383, -2147483648) << endl; }
