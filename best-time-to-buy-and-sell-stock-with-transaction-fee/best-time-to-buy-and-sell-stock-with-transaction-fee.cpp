class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> buys(n,0);
        vector<int> sells(n,0);
        buys[0]=-prices[0];
        sells[0]=0;
        for (int i=1;i<n;i++){
            buys[i]=max(sells[i-1]-prices[i],buys[i-1]);
            sells[i]=max(sells[i-1],buys[i]+prices[i]-fee);
        }
        return max(sells[n-1],buys[n-1]);
    }
};