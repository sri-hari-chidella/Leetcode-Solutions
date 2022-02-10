#define ll long long

class Solution {
public:
    int minDifficulty(vector<int>& A, int d) {
        int n=A.size();
        if (d>n)return -1;
        vector<vector<ll int>> dp(n,vector<ll int>(d,INT_MAX));
        int Max=A[0];
        for (int i=0;i<n;i++){
            Max=max(Max,A[i]);
            dp[i][0]=Max;
        }
        for (int j=1;j<d;j++){
            for (int i=0;i<n;i++){
                Max=A[i];
                for (int k=i-1;k>=0;k--){
                    dp[i][j]=min(dp[i][j],Max+dp[k][j-1]);
                    Max=max(Max,A[k]);
                }
            }
        }
        return dp[n-1][d-1];
    }
};