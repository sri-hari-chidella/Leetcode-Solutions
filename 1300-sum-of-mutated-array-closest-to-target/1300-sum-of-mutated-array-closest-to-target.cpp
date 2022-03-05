class Solution {
public:
    int ispos(vector<int> A,int mid){
        int ret=0;
        int n=A.size();
        for (int i=0;i<n;i++){
            if (A[i]<mid)ret+=A[i];
            else ret+=mid;
        }
        return ret;
    }
    
    int findBestValue(vector<int>& A, int target) {
        int n=A.size();
        int lo=INT_MAX;int hi=INT_MIN;
        for (int i=0;i<n;i++){
            lo=min(lo,A[i]);hi=max(hi,A[i]);
        }
        int mid=lo+(hi-lo)/2;
        int dif=INT_MAX;int ans=0;hi++;lo=0;
        while (lo<hi){
            mid=lo+(hi-lo)/2;
            int temp=ispos(A,mid);
            cout<<mid<<" "<<temp<<endl;
            if (abs(temp-target)<dif){dif=abs(temp-target);ans=mid;}
            else if(abs(temp-target)==dif)ans=min(ans,mid);
            if (temp<target)lo=mid+1;
            else hi=mid;
        }
        return ans;
    }
};