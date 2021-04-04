class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        for(int i=0;i<n;i++)
            matrix[i].resize(n);
        int num = 1;//当前步骤所填入数字
        int levelCount = n/2;//不包含n为奇数时矩阵中心的总层数1-0，2-1，3-1，4-2，5-2，6-3...
        for(int level=0;level<levelCount;level++){
            for(int i=0;i<n-1-level*2;i++)matrix[level][i+level]=num++;
            for(int i=0;i<n-1-level*2;i++)matrix[i+level][n-1-level]=num++;
            for(int i=0;i<n-1-level*2;i++)matrix[n-1-level][n-1-level-i]=num++;
            for(int i=0;i<n-1-level*2;i++)matrix[n-1-level-i][level]=num++;
        }
        if(n%2==1)matrix[(n-1)/2][(n-1)/2]=num;//处理n为奇数情况
        return matrix;
    }
};