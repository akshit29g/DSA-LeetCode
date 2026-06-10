class Solution {
public:
    vector<int> parent,sz;

    int findUpar(int node){
        if (node== parent[node]){
            return node;
        }
        return parent[node]= findUpar(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu= findUpar(u);
        int pv= findUpar(v);
        if (pu==pv) return;

        if (sz[pu]<sz[pv]){
            parent[pu]=pv;
            sz[pv]+=sz[pu];
        }
        else{
            parent[pv]=pu;
            sz[pu]+=sz[pv];
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()< n-1)
            return -1;
        parent.resize(n);
        sz.resize(n,1);
        
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
        int extraEdges=0;
        for (auto &it:connections){
            int u= it[0];
            int v= it[1];

            if (findUpar(u)== findUpar(v)){
                extraEdges++;
            }
            else{
                unionBySize(u,v);
            }
        }
        int components=0;
        for (int i=0;i<n;i++){
            if (parent[i]==i){
                components++;
            }
        }
        int needed= components-1;
        return (extraEdges>=needed) ? needed: -1;
    }
};