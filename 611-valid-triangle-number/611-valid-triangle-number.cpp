class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for (int i=n-1;i>=0;i--){
            int j=0;
            int k=i-1;
            while (j<k){
                if (nums[j]+nums[k]<=nums[i])j++;
                else{
                    ans+=k-j;
                    k--;
                }
            }
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};