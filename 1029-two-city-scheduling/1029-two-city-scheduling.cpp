class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int,int>> pq;
        int n=costs.size();
        for (int i=0;i<n;i++){
            pq.push({costs[i][1]-costs[i][0],costs[i][0]});
        }
        int ans=0;
        while (!pq.empty() && pq.size()>costs.size()/2){
            // cout<<pq.top().first<<endl;
            ans+=pq.top().second;pq.pop();
        }
        // cout<<ans<<endl;
        while (!pq.empty()){ans+=pq.top().first+pq.top().second;pq.pop();}
        return ans;
    }
};