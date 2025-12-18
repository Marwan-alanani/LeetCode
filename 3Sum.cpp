#include <bits/stdc++.h>

#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    map<int, int> count;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      count[nums[i]]++;
    }

    vector<int> filter;

    for (auto& [k, v] : count) {
      for (int i = 0; i < min(v, 3); i++) {
        filter.push_back(k);
      }
    }
    n = filter.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n;) {
      if (filter[i] > 0) break;
      for (int j = i + 1; j < n;) {
        if (filter[i] + filter[j] > 0) break;
        int lo = j + 1;
        int hi = n - 1;
        int mid;
        int value = -1 * (filter[i] + filter[j]);
        while (lo <= hi) {
          mid = (lo + hi) / 2;
          if (filter[mid] == value) {
            break;
          } else if (filter[mid] > value) {
            hi = mid - 1;
          } else {
            lo = mid + 1;
          }
        }
        if (filter[mid] + filter[i] + filter[j] == 0 && mid > j) {
          ans.push_back({filter[i], filter[j], filter[mid]});
        }
        int prev = filter[j];
        while (j < n && filter[j] == prev) {
          prev = filter[j];
          j++;
        }
      }

      int prev = filter[i];
      while (i < n && filter[i] == prev) {
        prev = filter[i];
        i++;
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
