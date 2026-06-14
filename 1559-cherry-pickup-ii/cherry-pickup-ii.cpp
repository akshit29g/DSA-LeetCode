class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n,
                vector<int>(n, 0)));

        // Base case
        for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {

                if (j1 == j2)
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                else
                    dp[m - 1][j1][j2] =
                        grid[m - 1][j1] +
                        grid[m - 1][j2];
            }
        }

        for (int i = m - 2; i >= 0; i--) {

            for (int j1 = 0; j1 < n; j1++) {

                for (int j2 = 0; j2 < n; j2++) {

                    int maxi = -1e8;

                    for (int d1 = -1; d1 <= 1; d1++) {

                        for (int d2 = -1; d2 <= 1; d2++) {

                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            int cherries =
                                (j1 == j2)
                                ? grid[i][j1]
                                : grid[i][j1] + grid[i][j2];

                            if (nj1 >= 0 && nj1 < n &&
                                nj2 >= 0 && nj2 < n) {

                                cherries +=
                                    dp[i + 1][nj1][nj2];
                            }
                            else {
                                cherries += -1e8;
                            }

                            maxi = max(maxi, cherries);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][n - 1];
    }
};