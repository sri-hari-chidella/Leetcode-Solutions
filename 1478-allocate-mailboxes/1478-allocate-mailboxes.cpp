class Solution {
public:
    int helper(int start,vector<int>& houses, int k,vector<vector<int>>&memo){
        if (k==1){
            int ans=0;
            int end=houses.size()-1;
            int med=(end-start)/2 + start;
            for (int i = start; i<=end;i++) ans+= abs(houses[i]-houses[med]);
            return ans;
        }
        if (memo[start][k]) return memo[start][k];
        int temp=start;
        int ans=INT_MAX;
        while (houses.size()-1-temp >=k-1){
            int med=(temp-start)/2 + start;
            int newans=0;
            for (int i=start;i<=temp;i++) newans+=abs(houses[i]-houses[med]);
            newans+=helper(temp+1,houses,k-1,memo);
            ans=min(ans,newans);
            temp++;
        }
        return memo[start][k]=ans;
    }
    int minDistance(vector<int>& houses, int k) {
        if (k>=houses.size()) return 0;
        vector<vector<int>>memo(houses.size(), vector<int>(k+1));
        sort(houses.begin(), houses.end());
        return helper(0,houses,k,memo);
    }
};