#include <bits/stdc++.h>
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> nodes;
    ListNode* cur = head;
    while (cur != nullptr) {
      nodes.push_back(cur);
      cur = cur->next;
    }
    if (n == nodes.size()) return head->next;
    if (n == 1) {
      nodes[nodes.size() - 2]->next = nullptr;
      return head;
    }
    int left = nodes.size() - n - 1;
    int right = nodes.size() - n + 1;
    nodes[left]->next = nodes[right];
    return head;
  }
};

ListNode* generate(vector<int> list) {
  ListNode* prev = nullptr;
  ListNode* head = nullptr;
  for (int i = 0; i < list.size(); i++) {
    ListNode* cur = new ListNode(list[i]);
    if (prev != nullptr) {
      prev->next = cur;
    }
    if (head == nullptr) head = cur;
    prev = cur;
  }
  return head;
}

int main() {
  vector<int> list = {1, 2, 3, 4, 5};
  ListNode* head = generate(list);
  Solution().removeNthFromEnd(head, 2);
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
}
