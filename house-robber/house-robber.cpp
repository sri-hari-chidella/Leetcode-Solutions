class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        ans[0]=nums[0];
        if (n>=2){
            ans[1]=max(nums[1],nums[0]);
            for (int i=2;i<n;i++){
                ans[i]=max(ans[i-1],nums[i]+ans[i-2]);
            }
        }
        return ans[n-1];
    }
};