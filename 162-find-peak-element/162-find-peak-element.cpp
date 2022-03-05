class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        int mid=lo+(hi-lo)/2;
        while (lo<=hi){
            mid=lo+(hi-lo)/2;
            long long left=mid-1>=0?nums[mid-1]:INT_MIN-(long long)1;
            long long right=mid+1<n?nums[mid+1]:INT_MIN-(long long)1;
            if (left<nums[mid] && nums[mid]>right)return mid;
            else if (left>right)hi=mid-1;
            else lo=mid+1;
        }
        return -1;
    }
};