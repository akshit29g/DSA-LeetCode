class Solution {
public:
    int dfs(vector<vector<int>>&g, int i, int j){
        int m=g.size(), n=g[0].size();
        if (i<0 || j<0 || i>=m || j>=n)
            return 1;
        if (g[i][j]==0)
            return 1;
        if (g[i][j]==-1)
            return 0;

        g[i][j]=-1;
        return dfs(g,i-1,j)+ dfs(g,i+1,j)+ dfs(g,i,j-1)+ dfs(g,i,j+1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]){
                    return dfs(grid,i,j);
                }
            }
        }
        return 0;
    }
};