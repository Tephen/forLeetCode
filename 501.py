# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        orderedList = []
        def traversal(root):#中序遍历得到有序数组
            if not root:
                return
            traversal(root.left)
            orderedList.append(root.val)
            traversal(root.right)
        traversal(root)

        count,maxCount = 0,0
        result = []
        for i in range(0,len(orderedList)):
            if i==0:
                count = 1
            elif orderedList[i]==orderedList[i-1]:
                count += 1
            else:#遇到新元素重新计数
                count = 1
            if count>maxCount:
                maxCount = count
                result.clear()
                result.append(orderedList[i])
            elif count==maxCount:
                result.append(orderedList[i])

        return result