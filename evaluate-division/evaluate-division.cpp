class Solution {
public:
    double solve(unordered_map<string,vector<pair<string,double>>> mp,string start,string dest,unordered_set<string> seen){
        if (start==dest)return 1.0;
        seen.insert(start);
        vector<pair<string,double>> v=mp[start];
        for (int i=0;i<v.size();i++){
            if (seen.find(v[i].first)==seen.end()){
                seen.insert(v[i].first);
                double temp=solve(mp,v[i].first,dest,seen);
                if (temp!=-1.0)return v[i].second*temp;
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> mp;
        for (int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],(double)1.0/(double)values[i]});
        }
        vector<double> ans;
        for (int i=0;i<queries.size();i++){
            unordered_set<string> seen;
            if (mp.find(queries[i][0])==mp.end() || mp.find(queries[i][1])==mp.end()){
                ans.push_back(-1.0);
            }
            else{
                seen.insert(queries[i][0]);
                ans.push_back(solve(mp,queries[i][0],queries[i][1],seen));
            }
        }
        return ans;
    }
};