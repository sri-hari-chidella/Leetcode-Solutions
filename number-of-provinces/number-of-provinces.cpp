class Solution {
public:
    int find(vector<int> &dsu, int i){
        while (dsu[i]>=0)i=dsu[i];
        return i;
    }
    
    void unionFind(vector<int> &dsu, int i, int j){
        int I=find(dsu,i);
        int J=find(dsu,j);
        if (I==J)return;
        if (dsu[I]<dsu[J]){
            dsu[I]+=dsu[J];dsu[J]=I;
        }
        else{
            dsu[J]+=dsu[I];dsu[I]=J;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> dsu(n,-1);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (isConnected[i][j]==1)unionFind(dsu,i,j);
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)cout<<dsu[i]<<" ";cout<<endl;
        for (int i=0;i<n;i++)ans+=(dsu[i]<=-1);
        return ans;
    }
};