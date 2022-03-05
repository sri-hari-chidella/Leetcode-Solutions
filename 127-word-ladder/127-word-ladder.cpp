class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s;
        for (int i=0;i<wordList.size();i++)s.insert(wordList[i]);
        q.push({beginWord,1});
        while (!q.empty()){
            string curr=q.front().first;int count=q.front().second;q.pop();
            if (curr==endWord)return count;
            for (int i=0;i<curr.size();i++){
                int org=curr[i];
                for (int j=0;j<26;j++){
                    curr[i]='a'+j;
                    if (s.find(curr)!=s.end()){q.push({curr,count+1});s.erase(curr);}
                }
                curr[i]=org;
            }
        }
        return 0;
    }
};