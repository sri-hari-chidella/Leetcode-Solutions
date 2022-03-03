class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int Min=intervals[0][0];
        int Max=intervals[0][1];
        vector<vector<int>> ans;
        while (i<n){
            if (intervals[i][0]<=Max && intervals[i][1]>=Min){
                Min=min(Min,intervals[i][0]);
                Max=max(Max,intervals[i][1]);
            }
            else{
                ans.push_back({Min,Max});
                Min=intervals[i][0];
                Max=intervals[i][1];
            }
            i++;
        }
        ans.push_back({Min,Max});
        return ans;
    }
};