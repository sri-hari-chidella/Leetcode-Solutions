class NumMatrix {
public:
    vector<vector<int>> sumMat;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();int m=matrix[0].size();
        sumMat=matrix;
        for (int i=1;i<n;i++)sumMat[i][0]+=sumMat[i-1][0];
        for (int i=1;i<m;i++)sumMat[0][i]+=sumMat[0][i-1];
        for (int i=1;i<n;i++){
            for (int j=1;j<m;j++){
                sumMat[i][j]+=sumMat[i-1][j]+sumMat[i][j-1]-sumMat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1==0 && col1==0)return sumMat[row2][col2];
        if (row1==0)return sumMat[row2][col2] - sumMat[row2][col1-1];
        if (col1==0)return sumMat[row2][col2] - sumMat[row1-1][col2];
        return sumMat[row2][col2] - sumMat[row1-1][col2] - sumMat[row2][col1-1]+ sumMat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */