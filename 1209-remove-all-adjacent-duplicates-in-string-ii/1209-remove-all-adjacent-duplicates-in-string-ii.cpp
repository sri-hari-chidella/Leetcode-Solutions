class Solution {
public:
    string removeDuplicates(string A, int k) {
        int n=A.size();
        int i=0;
        stack<pair<char,int>> s;
        while (i<n){
            if (s.empty()){s.push({A[i],1});i++;}
            else{
                if (A[i]==s.top().first){
                    int num=s.top().second;s.pop();
                    if (num+1<k)s.push({A[i],num+1});i++;
                }
                else{
                    if (s.top().second>=k)s.pop();
                    else {s.push({A[i],1});i++;}
                }
            }
        }
        string ret="";
        while (!s.empty()){
            char temp=s.top().first;int num=s.top().second;s.pop();
            for (int i=0;i<num;i++)ret+=temp;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};