class BrowserHistory {
public:
    vector<string> history;
    int maxInd;
    int currentInd;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        maxInd=0;currentInd=0;
    }
    
    void visit(string url) {
        if (currentInd==history.size()-1){
            history.push_back(url);currentInd++;maxInd++;
        }
        else{
            history[++currentInd]=url;
            maxInd=currentInd;
        }
    }
    
    string back(int steps) {
        currentInd=max(currentInd-steps,0);
        return history[currentInd];
    }
    
    string forward(int steps) {
        currentInd=min(currentInd+steps,maxInd);
        return history[currentInd];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */