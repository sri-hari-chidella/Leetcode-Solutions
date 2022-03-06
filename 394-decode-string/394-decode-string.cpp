class Solution {
public:
    string decodeString(string A) {
        stack<char> s;
        // for (int i=0;i<A.length();i++)cout<<i<<" "<<A[i]<<endl;
        for (int i=0;i<A.length();i++){
            if (A[i]==']'){
                // cout<<i<<" "<<A[i]<<endl;
                string temp="";
                while (!s.empty() && s.top()!='['){temp+=s.top();s.pop();}
                s.pop();
                int num=0;
                int factor=1;
                while (!s.empty() && s.top()>='0' && s.top()<='9'){num=num+((s.top()-'0')*factor);factor=factor*10;s.pop();}
                // cout<<temp<<" "<<num<<endl;
                reverse(temp.begin(),temp.end());
                for (int k=0;k<num;k++){
                    for (int j=0;j<temp.length();j++)s.push(temp[j]);
                }
            }
            else s.push(A[i]);
        }
        string ans="";
        while (!s.empty()){
            ans+=s.top();s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};