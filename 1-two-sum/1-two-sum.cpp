class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        vector<int> ans;
        int n=A.size();
        if (n==0)return ans;
        if (n==1)return ans;
        unordered_map<int,int> mp;
        for (int i=0;i<n;i++){
            if (mp.find(target-A[i])!=mp.end()){
                ans.push_back(mp[target-A[i]]);ans.push_back(i);
                return ans;
            }
            mp[A[i]]=i;
        }
        return ans;
    }
};