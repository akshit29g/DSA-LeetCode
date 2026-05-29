class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int MOD= 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        dp[0][0]=1;

        for (int dice=1; dice<=n; dice++){
            for (int sum=1; sum<=target; sum++){
                long long ways=0;
                for (int face=1; face<=k; face++){
                    if (sum- face>= 0)
                    ways+= dp[dice-1][sum-face];
                    ways%= MOD;
                }
                dp[dice][sum]= ways;
            }
        }
        return dp[n][target];
    }
};