class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for (int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for (auto i:mp)pq.push({i.second,i.first});
        string ans;
        while (!pq.empty()){
            pair<int,char> temp=pq.top();pq.pop();
            for (int i=0;i<temp.first;i++)ans+=temp.second;
        }
        return ans;
    }
};