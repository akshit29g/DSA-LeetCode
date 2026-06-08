class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();

        vector<vector<int>> revAdj(n);
        vector<int> indegree(n,0);

        for (int u=0; u<n; u++){
            for (int v:graph[u]){
                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;

        for (int i=0;i<n;i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safeNodes;

        while (!q.empty()){
            int node= q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int prev:revAdj[node]){
                indegree[prev]--;
                if (indegree[prev]==0)
                    q.push(prev);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};