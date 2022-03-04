class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        for (int i=0;i<min((unsigned long)k,nums.size());i++){
            while (!dq.empty() && (dq.back().second<i-k+1 || dq.back().first<nums[i]))dq.pop_back();
            dq.push_back({nums[i],i});
        }
        vector<int> ans;
        ans.push_back(dq.front().first);
        int i=k;
        while (i<nums.size()){
            while (!dq.empty() && dq.front().second<i-k+1)dq.pop_front();
            while (!dq.empty() && (dq.back().second<i-k+1 || dq.back().first<nums[i]))dq.pop_back();
            dq.push_back({nums[i],i});    
            ans.push_back(dq.front().first);
            i++;
        }
        return ans;
    }
};