class Solution {
public:
    int climbStairs(int n) {
        if (n<=1) return 1;
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for (int i=2;i<=n;i++){
            if(dp[i]!=-1) return dp[i];
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};