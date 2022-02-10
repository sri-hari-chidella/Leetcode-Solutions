#define ll long long

class Solution {
public:
    int minDifficulty(vector<int>& A, int d) {
        int n=A.size();
        if (d>n)return -1;
        int Max=A[0];
        vector<vector<int>> dp(n,vector<int>(d,1000000));
        for (int i=0;i<n;i++){
            Max=max(Max,A[i]);
            dp[i][0]=Max;
        }
        for (int i=1;i<n;i++){
            int Max=A[i];
            for (int j=i-1;j>=0;j--){
                for (int k=1;k<d;k++){
                    dp[i][k]=min(dp[i][k],dp[j][k-1]+Max);
                }
                Max=max(Max,A[j]);
            }
        }
        return dp[n-1][d-1];
    }
};