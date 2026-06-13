class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<int> prev(n,0), curr(n,0);
        for (int j=0;j<n;j++){
           prev[j]= matrix[0][j];
        }
        for (int i=1;i<n;i++){
            for (int j=0;j<n;j++){
                int up= matrix[i][j]+ prev[j];
                int ld= matrix[i][j]+ (j>0? prev[j-1]: (int)1e9);
                int rd= matrix[i][j]+ (j<n-1? prev[j+1]: (int)1e9);
                curr[j]= min({up,ld,rd});
            }
            prev= curr;
        }

        int ans= 1e9;
        for (int j=0;j<n;j++){
            ans= min(ans, prev[j]);
        }
        return ans;
    }
};