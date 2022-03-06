class RandomizedSet {
public:
    vector<int> arr;
    int ind;
    unordered_map<int,int> mp;
    
    RandomizedSet() {
        ind=-1;
    }
    
    bool insert(int val) {
        // cout<<mp.size()<<endl;
        if (mp.find(val)!=mp.end())return false;
        if (ind==arr.size()-1)arr.push_back(val);
        ind++;
        arr[ind]=val;
        mp[val]=ind;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val)==mp.end())return false;
        int prevInd=mp[val];
        swap(arr[prevInd],arr[ind]);
        ind--;
        mp.erase(val);
        if (prevInd<=ind)mp[arr[prevInd]]=prevInd;
        return true;
    }
    
    int getRandom() {
        int randInd=rand()%(ind+1);
        return arr[randInd];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */