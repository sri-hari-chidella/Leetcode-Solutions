class Solution {
public:
    unordered_set<string> ans;
    
    void solve(string &s, int extraf, int extrab, int i, string temp, int sum){
        if (i==s.size()){
            // cout<<temp<<" "<<sum<<endl;
            if (sum==0)ans.insert(temp);
            return;
        }
        if (s[i]=='('){
            solve(s,extraf,extrab,i+1,temp+s[i],sum+1);
            if (extraf>0)solve(s,extraf-1,extrab,i+1,temp,sum);
        }
        else if (s[i]==')'){
            if (sum!=0)solve(s,extraf,extrab,i+1,temp+s[i],sum-1);
            if (extrab>0)solve(s,extraf,extrab-1,i+1,temp,sum);
        }
        else solve(s,extraf,extrab,i+1,temp+s[i],sum--);
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        int extraf=0;int extrab=0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='(')extraf++;
            else if (s[i]==')'){
                extraf--;
                if (extraf<0){extraf=0;extrab++;}
            }
        }
        // cout<<extraf<<" "<<extrab<<endl;
        solve(s,extraf,extrab,0,"",0);
        vector<string> ret;
        for (auto i:ans){
            ret.push_back(i);
        }
        return ret;
    }
};