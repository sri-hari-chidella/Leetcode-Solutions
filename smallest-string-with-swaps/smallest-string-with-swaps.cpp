class Solution {
public:
    int find(vector<int> &dsu, int i){
        while (dsu[i]>=0)i=dsu[i];
        return i;
    }
    
    void merge(int a, int b, vector<int> &dsu){
        int A=find(dsu,a);
        int B=find(dsu,b);
        if (A==B)return;
        else if (dsu[A]<dsu[B]){
            dsu[A]+=dsu[B];
            dsu[B]=A;
        }
        else{
            dsu[B]+=dsu[A];
            dsu[A]=B;
        }
    }
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<int> dsu(n,-1);
        for (int i=0;i<pairs.size();i++){
            merge(pairs[i][0],pairs[i][1],dsu);
        }
        for (int i=0;i<n;i++)cout<<dsu[i]<<" ";cout<<endl;
        vector<char> ans;
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> mp;
        for (int i=0;i<n;i++){
            mp[find(dsu,i)].push(s[i]);
        }
        for (int i=0;i<n;i++){
            int parent = find(dsu,i);
            ans.push_back(mp[parent].top());
            mp[parent].pop();
        }
        string ret="";
        for (int i=0;i<ans.size();i++)ret+=ans[i];
        return ret;
    }
};
