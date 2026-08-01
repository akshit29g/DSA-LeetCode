class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if (i==j) return nums[i];
        if (dp[i][j]!= INT_MIN){
            return dp[i][j];
        }
        int takeLeft= nums[i]- solve(i+1,j,nums,dp);
        int takeRight= nums[j]- solve(i,j-1,nums,dp);

        return dp[i][j]=max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for (int i=0;i<n;i++){
            dp[i][i]= nums[i];
        }
        for (int len=2;len<=n;len++){
            for (int i=0;i+len-1<n;i++){
                int j= i+len-1;

                dp[i][j]= max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }

        return dp[0][n-1]>=0;
    }
};