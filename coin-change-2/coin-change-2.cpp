class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        sort(coins.begin(),coins.end());
        for (int j=0;j<coins.size();j++){
            for (int i=0;i<=amount;i++){
                if (i>=coins[j])dp[i]+=dp[i-coins[j]];
            }
        }
        return dp[amount];
    }
};