class Solution {
public:
    int coinChange(vector<int>& A, int amount) {
        vector<long long int> dp(amount+1,INT_MAX);
        sort(A.begin(),A.end());
        dp[0]=0;
        for (int i=1;i<=amount;i++){
            // cout<<i<<endl;
            for (int j=0;j<A.size();j++){
                if (A[j]>i)break;
                // cout<<i<<" "<<j<<endl;
                dp[i]=min(dp[i],dp[i-A[j]]+1);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};