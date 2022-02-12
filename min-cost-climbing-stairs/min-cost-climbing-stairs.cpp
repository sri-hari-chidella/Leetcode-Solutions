class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,0);
        if (n==0)return 0;
        dp[0]=0;
        if (n==1)return 0;
        dp[1]=0;
        for (int i=2;i<=n;i++){
            dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
        }
        return dp[n];
    }
};