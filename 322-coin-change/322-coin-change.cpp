class Solution {
public:
    int coinChange(vector<int>& A, int amount) {
        vector<long long int> dp(amount+1,INT_MAX);
        sort(A.begin(),A.end());
        dp[0]=0;
        for (int i=0;i<A.size();i++){
            for (int j=A[i];j<=amount;j++){
                dp[j]=min(dp[j-A[i]]+1,dp[j]);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};