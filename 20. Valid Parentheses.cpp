#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isValid(string s) {
    stack<int> st;
    for (auto ch : s) {
      if (ch == ')') {
        if (st.size() == 0 || st.top() != '(') return false;
        st.pop();
      } else if (ch == '}') {
        if (st.size() == 0 || st.top() != '{') return false;
        st.pop();
      } else if (ch == ']') {
        if (st.size() == 0 || st.top() != '[') return false;
        st.pop();
      } else {
        st.push(ch);
      }
    }
    return st.size() == 0;
  }
};
