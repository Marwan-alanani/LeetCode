#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string intToRoman(int num) {
    vector<int> nums = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    vector<string> strs = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                           "XC", "C",  "CD", "D",  "CM", "M"};

    string ans = "";
    while (num != 0) {
      for (int i = nums.size() - 1; i > -1; i--) {
        if (num - nums[i] >= 0) {
          ans += strs[i];
          num -= nums[i];
          break;
        }
      }
    }
    return ans;
  }
};

int main() { cout << Solution().intToRoman(3749) << endl; }
