class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int m= grid.size();
        int n= grid[0].size();
        if (j1<0 || j1>=n || j2<0 || j2>=n){
            return -1e8;
        }
        if (i==m-1){
            if (j1==j2) return grid[i][j1];
            return grid[i][j1]+ grid[i][j2];
        }
        if (dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi= -1e8;
        for (int d1=-1;d1<=1;d1++){
            for (int d2=-1;d2<=1;d2++){
                int cherries;
                if (j1==j2) cherries= grid[i][j1];
                else cherries= grid[i][j1]+ grid[i][j2];

                cherries+= solve(i+1,j1+d1,j2+d2,grid,dp);
                maxi= max(maxi,cherries);
            }
        }
        return dp[i][j1][j2]= maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n, vector<int> (n,-1)));
        return solve(0,0,n-1,grid,dp);
    }
};