class Solution {
public:
    int find(vector<int> &dsu, int a){
        int i=a;
        while (dsu[i]>=0)i=dsu[i];
        return i;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (i!=j)pq.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        vector<int> dsu(n,-1);int count=0;int ans=0;
        while (!pq.empty() && count<n-1){
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            int dist=pq.top().first;
            pq.pop();
            int A=find(dsu,a);int B=find(dsu,b);
            // cout<<a<<" "<<b<<endl;
            if (A!=B){
                if (A<B){
                    dsu[A]+=dsu[B];
                    dsu[B]=A;
                    ans+=dist;count++;
                }
                else{
                    dsu[B]+=dsu[A];
                    dsu[A]=B;ans+=dist;count++;
                }
            }
        }
        return ans;
    }
};