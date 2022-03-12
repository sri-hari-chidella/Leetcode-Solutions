class Solution {
public:
    int trap(vector<int>& A) {
        int n=A.size();
        if (n==0)return 0;
        int i=0;int j=n-1;
        int left_max=0;int right_max=0;
        int ans=0;
        while (i<j){
            if (A[i]<A[j]){
                if (A[i]>=left_max)left_max=A[i];
                else ans+=left_max-A[i];
                i++;
            }
            else{
                if (A[j]>=right_max)right_max=A[j];
                else ans+=right_max-A[j];
                j--;
            }
        }
        return ans;
    }
};