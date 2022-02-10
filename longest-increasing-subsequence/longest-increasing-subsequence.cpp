class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n=A.size();
        if (n==0)return 0;
        vector<int> dp;
        for (int i=0;i<n;i++){
            int index=upper_bound(dp.begin(),dp.end(),A[i])-dp.begin();
            if (index-1>=0 && dp[index-1]>=A[i])continue;
            if (index==dp.size())dp.push_back(A[i]);
            else dp[index]=A[i];
        }
        return dp.size();
    }
};