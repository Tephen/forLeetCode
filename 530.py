# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        orderedList = []
        def midOrderTraversal(root):
            if not root:
                 return
            midOrderTraversal(root.left)
            orderedList.append(root.val)
            midOrderTraversal(root.right)
        midOrderTraversal(root)
        res = float("inf")
        for i in range(0,len(orderedList)-1):
            res = min(res,orderedList[i+1]-orderedList[i])
        return res
