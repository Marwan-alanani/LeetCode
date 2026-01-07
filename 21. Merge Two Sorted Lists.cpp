#include <bits/stdc++.h>
using namespace std;
// * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* prev = nullptr;
    ListNode* head = prev;
    ListNode* nw = nullptr;

    while (list1 != nullptr || list2 != nullptr) {
      if (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
          nw = new ListNode(list1->val);
          list1 = list1->next;
        } else {
          nw = new ListNode(list2->val);
          list2 = list2->next;
        }
      } else if (list1 == nullptr) {
        nw = new ListNode(list2->val);
        list2 = list2->next;

      } else {
        nw = new ListNode(list1->val);
        list1 = list1->next;
      }
      if (prev == nullptr) {
        head = prev = nw;
      } else {
        prev->next = nw;
        prev = nw;
      }
    }
    return head;
  }
};

int main() {
  ListNode* list1 = new ListNode(1);
  list1->next = new ListNode(2);
  list1->next->next = new ListNode(4);
  ListNode* list2 = new ListNode(1);
  list2->next = new ListNode(3);
  list2->next->next = new ListNode(4);
  ListNode* head = Solution().mergeTwoLists(list1, list2);

  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
