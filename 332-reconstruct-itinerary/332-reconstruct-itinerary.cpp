class Solution {
public:    
    void solve(unordered_map<string,priority_queue<string,vector<string>,greater<string>>> &mp, string from, vector<string> &ans){
        while (!mp[from].empty()){
            string to=mp[from].top();mp[from].pop();
            solve(mp,to,ans);
        }
        ans.push_back(from);return;
    }
    
    vector<string> findItinerary(vector<vector<string>>& A) {
        int n=A.size();
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mp;
        for (int i=0;i<n;i++){
            mp[A[i][0]].push(A[i][1]);
        }
        vector<string> ans;
        solve(mp,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};