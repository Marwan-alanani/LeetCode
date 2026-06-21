#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* prev = dummy;
    while (prev->next != nullptr && prev->next->next != nullptr) {
      ListNode* cur = prev->next;
      ListNode* next = cur->next;
      prev->next = next;
      cur->next = next->next;
      next->next = cur;
      prev = cur;
    }
    return dummy->next;
  }
};
void printLinkedList(ListNode* head) {
  auto cur = head;
  while (cur != nullptr) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}
ListNode* convert(vector<int> arr) {
  ListNode* head = nullptr;
  ListNode* cur = nullptr;
  for (int i = 0; i < arr.size(); i++) {
    auto tmp = new ListNode(arr[i]);
    if (head == nullptr) {
      head = tmp;
    } else {
      cur->next = tmp;
    }
    cur = tmp;
  }
  return head;
}

int main() {
  vector<int> arr = {1, 2, 3, 4};
  ListNode* head = convert(arr);
  head = Solution().swapPairs(head);
  printLinkedList(head);
}
