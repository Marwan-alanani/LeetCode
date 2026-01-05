from math import *
import math
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):

    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool

        """
        if root is None:
            return True

        self.left =-1e18
        self.right = 1e18
        self.traverseLeft(root.left)
        self.traverseRight(root.right)
        if self.left < root.val < self.right :
            return self.isValidBST(root.left) and self.isValidBST(root.right)
        return False

    def traverseLeft(self, leftNode):
        if leftNode is None:
            return
        self.left = max(leftNode.val , self.left)
        self.traverseLeft(leftNode.left)
        self.traverseLeft(leftNode.right)

    def traverseRight(self,rightNode):
        if rightNode is None:
            return
        self.right = min(rightNode.val , self.right)
        self.traverseRight(rightNode.left)
        self.traverseRight(rightNode.right)







x = TreeNode(3)
x.left = TreeNode(1)
x.right = TreeNode(5)
x.left.left = TreeNode(0)
x.left.right= TreeNode(2)
x.right.left = TreeNode(4)
x.right.right = TreeNode(6)

print(Solution().isValidBST(x))
