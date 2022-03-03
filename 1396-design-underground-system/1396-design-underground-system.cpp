class UndergroundSystem {
public:
    unordered_map<string,unordered_map<string,pair<int,int>>> mp;
    unordered_map<int,pair<string,int>> customer;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id]={stationName,t};
        
    }
    
    void checkOut(int id, string stationName, int t) {
        int timeDiff=t-customer[id].second;
        string startStation = customer[id].first;
        pair<int,int> temp = mp[startStation][stationName];
        mp[startStation][stationName] = {temp.first + timeDiff,temp.second+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int,int> temp = mp[startStation][endStation];
        return (double)temp.first/(double)temp.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */