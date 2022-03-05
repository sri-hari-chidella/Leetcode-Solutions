class Solution {
public:
    vector<int> arr;
    vector<int> init;
    
    Solution(vector<int>& nums) {
        arr=nums;
        init=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr=init;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i=0;i<arr.size()-1;i++){
            int random=rand()%(arr.size()-i);
            swap(arr[i],arr[i+random]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */