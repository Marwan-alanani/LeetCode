# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        d1 = []
        d2 = []

        while l1 != None:
            d1.append(l1.val)
            l1 = l1.next

        while l2 != None:
            d2.append(l2.val)
            l2 = l2.next

        d1.reverse()
        d2.reverse()

        sm = [0] * ((max(len(d1), len(d2))) + 1)
        idx1 = len(d1) - 1
        idx2 = len(d2) - 1
        idx3 = len(sm) - 1
        carry = 0

        while idx1 >= 0 or idx2 >= 0:

            if idx1 >= 0 and idx2 >= 0:
                sm[idx3] = (d1[idx1] + d2[idx2] + carry) % 10
                carry = (d1[idx1] + d2[idx2] + carry) // 10

            elif idx1 >= 0:
                sm[idx3] = (d1[idx1] + carry) % 10
                carry = (d1[idx1] + carry) // 10

            elif idx2 >= 0:
                sm[idx3] = (d2[idx2] + carry) % 10
                carry = (d2[idx2] + carry) // 10

            idx1 -= 1
            idx2 -= 1
            idx3 -= 1

        sm [idx3] = carry

        start = 0;

        while start < len(sm) and sm[start] == 0:
            start +=1

        if start == len(sm):
            return ListNode(0)

        idx = len(sm) - 1
        head = ListNode(sm[idx])
        current = head
        idx-=1

        while idx >= start:
            nw = ListNode(sm[idx])
            current.next = nw
            current = nw
            idx-=1

        return head


def main():
    l1 = convert([9,9,9,9,9,9,9])
    l2 = convert([9,9,9,9])
    head = Solution().addTwoNumbers(l1 , l2)

    while head != None:
        print(head.val)
        head = head.next


def convert(lst : list):
    head = ListNode(lst[0])
    current = head
    for i in range(1 , len(lst)):
        nw = ListNode(lst[i])
        current.next = nw
        current = nw

    return head

main()
