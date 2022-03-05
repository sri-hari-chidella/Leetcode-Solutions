class Solution {
public:
    vector<vector<int>> ans;
        
    void solve(vector<int> &A,int ind, vector<int> &v){
        if (ind==A.size()){
            ans.push_back(v);return;
        }
        solve(A,ind+1,v);
        v.push_back(A[ind]);
        solve(A,ind+1,v);
        v.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& A) {
        vector<int> v;
        solve(A,0,v);
        return ans;
    }
};