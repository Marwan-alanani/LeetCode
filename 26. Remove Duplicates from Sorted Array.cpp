#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 1, j = 1;
    while (j < nums.size()) {
      while (j < nums.size() && nums[j] == nums[i - 1]) j++;
      if (j == nums.size()) break;
      swap(nums[j++], nums[i++]);
    }
    return i;
  }
};

int main() {
  vector<int> arr = {1, 1, 1,1,1,1};
  int k = Solution().removeDuplicates(arr);
  for (int i = 0; i < k; i++) cout << arr[i] << " ";
  cout << endl;
}
