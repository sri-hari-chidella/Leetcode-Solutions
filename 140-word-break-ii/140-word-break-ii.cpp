class Solution {
public:
    unordered_set<string> mp;
    // vector<string> ans;
    
    vector<string> solve(string A, int ind){
        if (ind>=A.size())return {""};
        vector<string> ans;
        string temp="";
        for (int i=ind;i<A.size();i++){
            temp+=A[i];
            if (mp.find(temp)!=mp.end()){
                vector<string> res=solve(A,i+1);
                for (int j=0;j<res.size();j++){
                    if (res[j]!="")ans.push_back(temp+" "+res[j]);
                    else ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& A) {
        for (int i=0;i<A.size();i++)mp.insert(A[i]);
        return solve(s,0);
    }
};