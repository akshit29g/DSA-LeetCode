class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU ds(n * n);

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        auto nodeNo = [&](int r, int c) {
            return r * n + c;
        };

        // Step 1: connect all existing 1s
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 0) continue;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        ds.unionBySize(
                            nodeNo(r, c),
                            nodeNo(nr, nc)
                        );
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: try converting each 0
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) continue;

                unordered_set<int> comps;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        comps.insert(
                            ds.findUPar(nodeNo(nr, nc))
                        );
                    }
                }

                int currSize = 1;

                for (auto parent : comps) {
                    currSize += ds.size[parent];
                }

                ans = max(ans, currSize);
            }
        }

        // Step 3: handle all-1s case
        for (int i = 0; i < n * n; i++) {
            if (ds.findUPar(i) == i) {
                ans = max(ans, ds.size[i]);
            }
        }

        return ans;
    }
};