class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if (n==0)return 0;
        vector<int> dp(n,0);
        if (s[0]=='0')return 0;
        for (int i=1;i<n;i++){if (s[i]=='0' && ((s[i-1]-'0')>2 || (s[i-1]-'0'==0)))return 0;}
        dp[0]=1;
        if (n==1)return 1;
        if ((s[0]-'0')*10 + (s[1]-'0') <= 26) dp[1]=1;
        if (s[1]!='0') dp[1]+=1;
        for (int i=2;i<n;i++){
            if ((s[i-1]-'0')*10 + s[i]-'0' <=26 && s[i-1]!='0')dp[i]+=dp[i-2];
            if (s[i]!='0')dp[i]+=dp[i-1];
        }
        for (int i=0;i<n;i++)cout<<dp[i]<<" ";cout<<endl;
        return dp[n-1];
    }
};
