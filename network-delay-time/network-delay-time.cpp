#define pii pair<int,int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int K) {
        vector<vector<pair<int,int>>> graph(n);
        for (int i=0;i<times.size();i++){
            graph[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        vector<int> visited(n,0);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,K-1});
        int ans=0;
        while (!pq.empty()){
            int dist=pq.top().first;int node=pq.top().second;
            pq.pop();
            if (visited[node]==0){
                ans=max(dist,ans);
                visited[node]=1;
                for (int i=0;i<graph[node].size();i++){
                    if (!visited[graph[node][i].first]){
                        pq.push({dist+graph[node][i].second,graph[node][i].first});
                    }
                }
            }
        }
        for (int i=0;i<n;i++){
            if (visited[i]==0)return -1;
        }
        return ans;
    }
};