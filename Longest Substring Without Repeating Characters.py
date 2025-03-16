from collections import *
from sys import argv
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        cur = deque()
        seen = set()
        i = 0
        n = len(s)
        best = 0

        while i < n:

            if s[i] in seen:
                while cur[0] != s[i]:
                    seen.remove(cur[0])
                    cur.popleft()
                cur.popleft()

            seen.add(s[i])
            cur.append(s[i])
            best = max(best , len(cur))

            i+=1
        return best

def main():
    s = "bbbbb"
    print(Solution().lengthOfLongestSubstring(s))

main()
