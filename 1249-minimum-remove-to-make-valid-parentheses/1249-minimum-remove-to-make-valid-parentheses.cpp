class Solution {
public:
    string minRemoveToMakeValid(string A) {
        int n=A.length();
        string ans="";
        stack<pair<char,int>> s;
        vector<bool> done(n,false);
        for (int i=0;i<n;i++){
            if (A[i]==')'){
                if (!s.empty()){
                    done[s.top().second]=true;
                    s.pop();
                    done[i]=true;
                }
            }
            else if (A[i]=='('){
                s.push({'(',i});
            }
            else done[i]=true;
        }
        for (int i=0;i<n;i++){
            if (done[i]==true)ans+=A[i];
        }
        return ans;
    }
};