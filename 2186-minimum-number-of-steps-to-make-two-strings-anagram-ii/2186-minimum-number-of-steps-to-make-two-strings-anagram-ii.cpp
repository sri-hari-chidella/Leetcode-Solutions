class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size();int m=t.size();
        vector<int> mp(26,0);
        for (int i=0;i<n;i++)mp[s[i]-'a']++;
        for (int i=0;i<m;i++)mp[t[i]-'a']--;
        int ans=0;
        for (auto i:mp)ans+=abs(i);
        return ans;
    }
};