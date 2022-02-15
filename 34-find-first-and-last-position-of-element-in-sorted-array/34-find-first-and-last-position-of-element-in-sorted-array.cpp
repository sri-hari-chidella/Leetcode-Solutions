class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0){
            vector<int> v={-1,-1};
            return v;
        }
        int lo=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int hi=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int> ans;
        if (lo<nums.size() && nums[lo]==target)ans.push_back(lo);
        else ans.push_back(-1);
        if (hi!=0 && hi-1>=0 && hi-1<nums.size() && nums[hi-1]==target)ans.push_back(hi-1);
        else ans.push_back(-1);
        sort(ans.begin(),ans.end());
        return ans;
    }
};