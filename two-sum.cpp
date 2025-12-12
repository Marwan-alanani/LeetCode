#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int other = target - nums[i];
            if (other == nums[i] && m[nums[i]].size() > 1)
            {
                ans.push_back(m[nums[i]][0]);
                ans.push_back(m[nums[i]][1]);
                break;
            }
            else if (m.count(other) && other != nums[i])
            {
                ans.push_back(i);
                ans.push_back(m[other][0]);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> test = {3, 2, 4};
    int t = 6;
    vector<int> res = Solution().twoSum(test, t);
    for (auto &el : res)
        cout << el << " ";
}
