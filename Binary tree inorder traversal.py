# Definition for a binary tree node.
class TreeNode:
 def __init__(self, val=0, left=None, right=None):
     self.val = val
     self.left = left
     self.right = right

class Solution:
    nodes = []
    def inorderTraversal(self, root ) :
        self.nodes = []
        self.dfs(root)
        return self.nodes

    def dfs(self, node) :
        if node is None:
            return
        self.dfs(node.left)
        self.nodes.append(node.val)
        self.dfs(node.right)



def main():
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    print(Solution().inorderTraversal(root))

main()
