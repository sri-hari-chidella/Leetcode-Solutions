class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minheap.push(num);
        if (minheap.size()>maxheap.size()+1){
            maxheap.push(minheap.top());minheap.pop();
        }
        if (!maxheap.empty() && minheap.top()<maxheap.top()){
            maxheap.push(minheap.top());minheap.pop();
            minheap.push(maxheap.top());maxheap.pop();
        }
    }
    
    double findMedian() {
        if ((minheap.size()+maxheap.size())%2==1)return minheap.top();
        return (double)(maxheap.top()+minheap.top())/(double)2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */