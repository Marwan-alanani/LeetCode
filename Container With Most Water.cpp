#include <bits/stdc++.h>;

#include <algorithm>
#include <climits>
#include <cstdint>
#include <vector>
using namespace std;
#define ll long long
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int mxArea = INT_MIN;
    while (i < j) {
      mxArea = max(mxArea, min(height[i], height[j]) * (j - i));
      if (height[i] > height[j])
        j--;
      else
        i++;
    }
    return mxArea;
  }
};

int main() {}
