class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        if (n==0)return 0;
        int m=A[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=A[0][0];
        for (int i=0;i<m;i++)dp[0][i]=A[0][i];
        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++){
                dp[i][j]=min((j-1>=0?dp[i-1][j-1]:INT_MAX),min(dp[i-1][j],(j+1<m?dp[i-1][j+1]:INT_MAX)))+A[i][j];
            }
        }
        int ans=INT_MAX;
        for (int i=0;i<m;i++)ans=min(ans,dp[n-1][i]);
        return ans;
    }
};