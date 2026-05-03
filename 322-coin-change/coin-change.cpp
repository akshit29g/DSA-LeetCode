class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e9);
        dp[0]=0;

        for (int coin:coins){
            for (int t=coin;t<=amount;t++){
                dp[t]=min(dp[t],1+dp[t-coin]);
            }
        }
        return dp[amount]>=1e9? -1:dp[amount];
    }
};