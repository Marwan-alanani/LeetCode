#include <bits/stdc++.h>

#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      int cur = nums[i];
      if (nums[i] > 0 || (i > 0 && cur == nums[i - 1])) continue;
      int lo = i + 1, hi = n - 1;
      while (lo < hi) {
        if (cur + nums[lo] + nums[hi] == 0) {
          ans.push_back({cur, nums[lo], nums[hi]});
          while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
          while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
          lo++;
          hi--;
        } else if (cur + nums[lo] + nums[hi] < 0)
          lo++;
        else
          hi--;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> in = {-1, 0, 1, 0};
  auto ans = Solution().threeSum(in);
  for (auto el : ans) {
    for (auto el2 : el) {
      cout << el2 << " ";
    }
    cout << endl;
  }
  cout << endl;
}
