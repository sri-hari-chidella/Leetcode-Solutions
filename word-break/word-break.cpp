class Solution {
public:
    bool wordBreak(string A, vector<string>& wordDict) {
        unordered_set<string> s;
        for (int i=0;i<wordDict.size();i++)s.insert(wordDict[i]);
        vector<bool> dp(A.size()+1,false);
        string temp="";
        for (int i=0;i<A.size();i++){
            string temp="";
            for (int j=i;j<A.size();j++){
                temp+=A[j];
                if (s.find(temp)!=s.end()){
                    dp[j]=((i-1>=0)?dp[i-1]:true)||dp[j];
                }
            }
        }
        return dp[A.size()-1];
    }
};