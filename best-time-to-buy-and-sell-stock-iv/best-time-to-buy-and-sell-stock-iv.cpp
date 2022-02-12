class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if (n==0)return 0;
        if (k==0)return 0;
        if (k>=n/2){
            int ans=0;
            for (int i=1;i<n;i++){
                if (prices[i]>prices[i-1])ans+=prices[i]-prices[i-1];
            }
            return ans;
        }
        vector<vector<long long int>> buy(n,vector<long long int>(k,INT_MIN));
        vector<vector<long long int>> sell(n,vector<long long int>(k,INT_MIN));
        buy[0][0]=-prices[0];sell[0][0]=0;
        long long int Min=prices[0];
        for (int i=1;i<n;i++){
            Min=min(Min,(long long)prices[i]);
            buy[i][0]=max(buy[i-1][0],-Min);
            sell[i][0]=max(sell[i-1][0],prices[i]-Min);
        }
        for (int i=1;i<n;i++){
            for (int j=1;j<k;j++){
                buy[i][j]=max(buy[i-1][j],sell[i-1][j-1]-prices[i]);
                sell[i][j]=max(sell[i-1][j],buy[i][j]+prices[i]);
            }
        }
        // for (int i=0;i<n;i++){
        //     for (int j=0;j<k;j++)cout<<buy[i][j]<<" ";cout<<endl;
        // }
        // cout<<endl;
        // for (int i=0;i<n;i++){
        //     for (int j=0;j<k;j++)cout<<sell[i][j]<<" ";cout<<endl;
        // }
        return max(sell[n-1][k-1],buy[n-1][k-1]);
    }
};