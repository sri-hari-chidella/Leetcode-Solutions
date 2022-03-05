#define ll long long
class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;n--;
        long double ans=1;
        int start=max(m,n);
        int end=min(m,n);
        int i=start+1;
        int j=1;
        while (i<=m+n && j<=end){
            ans*=((long double)i/(long double)j);
            i++;j++;
        }
        // cout<<ans<<endl;
        if ((ans-floor(ans))>=(ceil(ans)-ans))return ceil(ans);
        else return floor(ans);
        return ans;
    }
};