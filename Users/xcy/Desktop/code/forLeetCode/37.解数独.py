# @before-stub-for-debug-begin
from python3problem37 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=37 lang=python3
#
# [37] 解数独
#

# @lc code=start
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def backTrack(board) ->bool:
            def notValid(row,col,num):
                for i in range(0,9):
                    if board[row][i]==num:
                        return True
                    if board[i][col]==num:
                        return True
                startRow,startCol = (row//3)*3,(col//3)*3
                for i in range(startRow,startRow+3):
                    for j in range(startCol,startCol+3):
                        if board[i][j]==num:
                            return True
                return False

            for row in range(0,9):
                for col in range(0,9):
                    if board[row][col]!=".":
                        continue
                    for num in [str(n) for n in range(1,10)]:
                        if notValid(row,col,num):
                            continue
                        board[row][col] = num
                        if backTrack(board):
                            return True
                        board[row][col] = "."
                    return False
            return True
        backTrack(board)
# @lc code=end

