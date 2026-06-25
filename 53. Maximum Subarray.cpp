#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre = vector<int>(nums.size() + 2, -1e5);
    for (int i = 1; i <= n; i++) {
      if (nums[i - 1] + pre[i - 1] > nums[i - 1]) {
        pre[i] = nums[i - 1] + pre[i - 1];
      } else {
        pre[i] = nums[i - 1];
      }
    }
    auto mx = max_element(pre.begin(), pre.end());
    return *mx;
  }
};

int main() {
  vector<int> arr = {5, 4, -1, 7, 8};
  cout << Solution().maxSubArray(arr) << endl;
}
