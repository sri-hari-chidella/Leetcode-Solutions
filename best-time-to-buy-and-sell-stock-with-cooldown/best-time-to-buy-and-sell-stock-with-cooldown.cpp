class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n==0)return 0;
        vector<int> buys(n,0);
        vector<int> sells(n,0);
        buys[0]=-prices[0];
        sells[0]=0;
        for (int i=1;i<n;i++){
            buys[i]=max(buys[i-1],((i-2>=0)?sells[i-2]:0)-prices[i]);
            sells[i]=max(sells[i-1],buys[i]+prices[i]);
        }
        return sells[n-1];
    }
};