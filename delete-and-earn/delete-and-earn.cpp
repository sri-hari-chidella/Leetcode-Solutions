#define MAX 10000

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(MAX+1,0);
        for (int i=0;i<nums.size();i++)count[nums[i]]++;
        vector<int> ans(MAX+1,0);
        ans[0]=count[0];
        ans[1]=max(ans[0],count[1]);
        for (int i=2;i<=MAX;i++){
            ans[i]=max(ans[i-1],(count[i]*i)+ans[i-2]);
        }
        // cout<<ans[3]<<endl;
        return ans[MAX];
    }
};