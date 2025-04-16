#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    int s = 0;
    int e = 0;
    ll count = 0;
    map<int, ll> m;
    ll ans = 0;

    while (e < nums.size()) {
      int num = nums[e];
      if (m.count(num)) {
        m[num]++;
        count += m[num];
      } else
        m[num] = 0;

      while (s <= e && count >= k) {
        ans += nums.size() - e;
        ll x = nums[s];
        count -= m[x];
        m[x]--;
        s++;
      }
      e++;
    }
    return ans;
  }
};

int main() {
  vector<int> x = {1, 1, 1, 1, 1};
  cout << Solution().countGood(x, 10) << endl;
}

