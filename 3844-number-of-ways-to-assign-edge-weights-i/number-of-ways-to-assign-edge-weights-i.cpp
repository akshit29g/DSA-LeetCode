class Solution {
public:
    static const int MOD= 1e9+7;
    long long modpow(long long a, long long b){
        long long res=1;
        while(b){
            if (b&1) res=(res*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return res;
    }
    int maxDepth=0;

    void dfs(int node, int parent, int depth, vector<vector<int>>& adj){
        maxDepth= max(maxDepth, depth);
        for (int nei:adj[node]){
            if (nei!=parent){
                dfs(nei, node, depth+1, adj);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n= edges.size()+1;
        vector<vector<int>> adj(n+1);
        for (auto &e: edges){
            int u= e[0];
            int v= e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,-1,0,adj);
        return modpow(2,maxDepth-1);
    }
};