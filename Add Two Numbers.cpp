#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
#include <cstddef>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    vector<int> d1;
    vector<int> d2;
    while (l1 != NULL) {
      d1.push_back(l1->val);
      l1 = l1->next;
    }
    while (l2 != NULL) {
      d2.push_back(l2->val);
      l2 = l2->next;
    }
    reverse(d1.begin(), d1.end());
    reverse(d2.begin(), d2.end());
    int idx1 = d1.size() - 1;
    int idx2 = d2.size() - 1;
    vector<int> sum(max(d1.size(), d2.size()) + 1);
    int idx3 = sum.size() - 1;
    int carry = 0;
    while (idx1 >= 0 || idx2 >= 0) {

      if (idx1 >= 0 && idx2 >= 0) {

        sum[idx3] = ((d1[idx1] + d2[idx2] + carry) % 10);
        carry = (d1[idx1] + d2[idx2] + carry) / 10;

      } else if (idx1) {
        sum[idx3] = (d1[idx1] + carry) % 10;
        carry = (d1[idx1] + carry) / 10;
      } else if (idx2) {

        sum[idx3] = (d2[idx2] + carry) % 10;
        carry = (d2[idx2] + carry) / 10;
      }

      idx1--;
      idx2--;
      idx3--;
    }

    int start = 0;

    while (start < sum.size() && sum[start] == 0)
      start++;

    if (start == sum.size()) {
      ListNode *x = new ListNode(0);
      return x;
    }

    int idx = sum.size() - 1;
    ListNode *head = NULL;
    ListNode *current = NULL;

    while (idx >= start) {
      if (head == NULL) {
        head = new ListNode(sum[idx]);
        head->next = NULL;
        current = head;
      } else {
        ListNode nw = ListNode(sum[idx]);
        nw.next = NULL;
        current->next = &nw;
        current = &nw;
      }
      idx--;
    }
    return head;
  }
};

int main() {
  ListNode x = ListNode(0);
  ListNode y = ListNode(1);
  x.next = &y;
  ListNode b = ListNode(7);
  ListNode c = ListNode(8);
  b.next = &c;
  ListNode *head = Solution().addTwoNumbers(&x, &b);

  while (head != NULL) {
     int x = head->val;
     cout<<x;
    head = head->next;
  }
  cout << endl;
}
