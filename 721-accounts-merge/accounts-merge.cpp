class Solution {
public:
    vector<int> parent, sz;

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(sz[pu] < sz[pv]) {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        } else {
            parent[pv] = pu;
            sz[pu] += sz[pv];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        sz.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string,int> mailToNode;

        for(int i = 0; i < n; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if(mailToNode.find(mail) == mailToNode.end()) {
                    mailToNode[mail] = i;
                }
                else {
                    unionBySize(i, mailToNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        for(auto &it : mailToNode) {

            string mail = it.first;
            int node = it.second;

            int parentNode = findUPar(node);

            mergedMail[parentNode].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {

            if(mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto &mail : mergedMail[i])
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};