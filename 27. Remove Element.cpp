#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int r = nums.size() - 1, l = nums.size() - 1;
    int k = 0;
    while (l > -1) {
      while (r > -1 && nums[r] == val) {
        r--;
      }
      if (r < l) l = r;
      while (l > -1 && nums[l] != val) {
        k++;
        l--;
      }
      if (l == -1) break;
      swap(nums[l], nums[r]);
      l--;
    }
    return k;
  }
};

