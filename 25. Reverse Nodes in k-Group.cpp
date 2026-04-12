#include <bits/stdc++.h>

#include <climits>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) return head;
    ListNode* headOfK = head;
    ListNode* prevTail = nullptr;
    ListNode* cur = head;
    int tot = 0;
    while (cur != nullptr) {
      cur = cur->next;
      int count = 1;
      ListNode* curTail = nullptr;
      while (cur != nullptr && count < k) {
        if (count == 1) curTail = headOfK;
        ListNode* tmp = cur->next;
        cur->next = headOfK;
        curTail->next = tmp;
        headOfK = cur;
        // cur = tmp is like cur = cur->next
        cur = tmp;
        count++;
      }
      if (prevTail != nullptr) prevTail->next = headOfK;
      tot++;
      if (tot == 1) head = headOfK;
      if (cur == nullptr) break;
      headOfK = cur;
      prevTail = curTail;
    }
    return head;
  }
};

ListNode* construct(vector<int> arr) {
  ListNode* head = nullptr;
  ListNode* prev = nullptr;
  for (auto& num : arr) {
    ListNode* cur = new ListNode(num);
    cur->next = nullptr;
    if (head == nullptr) {
      head = prev = cur;
      continue;
    }
    prev->next = cur;
    prev = cur;
  }
  return head;
}

int main() {
  ListNode* head = construct({1, 2, 3, 4, 5});
  cout << "list before : " << endl;
  ListNode* cur = head;
  while (cur != nullptr) {
    cout << cur->val << "  ";
    cur = cur->next;
  }
  cout << endl;
  cur = head;

  cur = Solution().reverseKGroup(head, 3);
  cout << "list after : " << endl;
  while (cur != nullptr) {
    cout << cur->val << "  ";
    cur = cur->next;
  }
}
