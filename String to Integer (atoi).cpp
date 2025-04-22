#include <bits/stdc++.h>

#include <cstdint>

using namespace std;

#define ll long long

class Solution {
 public:
  int myAtoi(string s) {
    int idx = 0;
    ll number = 0;
    int sign = 1;
    int n = (int)s.size();
    while (idx < n && s[idx] == ' ') idx++;
    if (s[idx] == '-' || s[idx] == '+') {
      if (s[idx] == '-') sign *= -1;
      idx++;
    }

    int start;
    if (idx < n && isNumber(s[idx]))
      start = idx;
    else
      return 0;

    while (idx < n && isNumber(s[idx])) idx++;

    string sn = s.substr(start, idx - start);
    idx = 0;
    while (idx < n && sn[idx] == '0') idx++;
    sn = sn.substr(idx);

    if (sn.size() > 11) {
      if (sign == -1) return INT32_MIN;
      return INT32_MAX;
    }

    reverse(sn.begin(), sn.end());

    ll mult = 1;
    n = (int)sn.size();
    idx = 0;
    while (idx < n && idx < 11) {
      number += (sn[idx] - '0') * mult;
      idx++;
      mult *= 10;
    }
    if (sign == 1 && number > INT32_MAX) {
      number = INT32_MAX;
    } else if (sign == -1 && number * sign < INT32_MIN) {
      number = (ll)INT32_MIN * -1;
    }
    return number * sign;
  }
  bool isNumber(char x) { return x - '0' >= 0 && x - '0' <= 9; }
};

int main() { cout << Solution().myAtoi("4193 with words") << endl; }
