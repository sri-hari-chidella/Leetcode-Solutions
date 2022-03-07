class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        int n=A.length();
        if (n==0)return 0;
        int i=0;int j=0;
        int ans=0;
        unordered_map<char,int> mp;
        while (i<n && j<n){
            if (mp.find(A[j])==mp.end()){
                mp[A[j]]=j+1;j++;
                ans=max(ans,j-i);
            }
            else{
                i=max(i,mp[A[j]]);
                mp[A[j]]=j+1;j++;
                ans=max(ans,j-i);
            }
        }
        return ans;
    }
};