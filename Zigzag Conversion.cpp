#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if(numRows == 1) return s;

    vector<int> indices(s.size());
    int idx = 0;
    set<int> vis;

    for (int i = 1; i <= numRows; i++) {
      if (idx == s.size()) break;
      int cur = i - 1;
      indices[idx] = cur;
      vis.insert(cur);
      idx++;

      int fn = numRows - (i - 1) + numRows - (i - 1) - 2;
      int rn = i + i - 2;
      int chosen = fn;

      while (cur + chosen < s.size()) {

        cur += chosen;
        if(!vis.count(cur)){
          indices[idx] = cur;
          idx++;
          vis.insert(cur);
        }

        if(chosen == fn) chosen = rn;
        else chosen = fn;
      }
    }
    vector<char> word(s.size());
    for (int i = 0; i < s.size(); i++) {
      int idx = indices[i];
      word[i] = s[idx];
    }
    string x = "";
    for (int i = 0; i < s.size(); i++) x += word[i];
    return x;
  }
};

int main(){
  cout<<Solution().convert("PAYPALISHIRING", 3)<<endl;
}
