class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;
    void backTrack(int n,int row){
        if (row == n) {
            result.push_back(path);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (notValid(row, col,n)) continue;
            path[row][col] = 'Q'; // 放置皇后
            backTrack(n, row + 1);
            path[row][col] = '.'; // 回溯，撤销皇后
        }
    }
    bool notValid(int row,int col,int n){
        for (int i = 0; i < n; i++) {
            if (path[i][col] == 'Q') {
                return true;
            }
        }
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (path[i][j] == 'Q') {
                return true;
            }
        }
        // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (path[i][j] == 'Q') {
                return true;
            }
        }
        return false;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        path = vector<string> (n,string(n,'.'));
        backTrack(n,0);
        return result;
    }
};