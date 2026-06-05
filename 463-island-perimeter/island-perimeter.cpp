class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int land=0, shared=0;
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]){
                    land++;
                    if (i+1<m && grid[i+1][j])
                        shared++;
                    if (j+1<n && grid[i][j+1])
                        shared++;
                }
            }
        }
        return 4*land-2*shared;
    }
};