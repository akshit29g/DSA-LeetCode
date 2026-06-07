class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visit){
        visit[node]=1;
        for (int nei=0; nei<isConnected.size(); nei++){
            if (isConnected[node][nei]==1 && !visit[nei]){
                dfs(nei, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        int count=0;
        vector<int> visit(n,0);
        for (int i=0; i<n; i++){
            if (!visit[i]){
                count++;
                dfs(i,isConnected,visit );
            }
        }
        return count;
    }
};