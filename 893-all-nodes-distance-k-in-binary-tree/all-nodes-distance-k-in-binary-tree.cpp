class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> bfs;

        bfs.push(target);
        vis[target] = true;

        int dist = 0;

        while (!bfs.empty()) {

            int sz = bfs.size();

            if (dist == k)
                break;

            dist++;

            while (sz--) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    bfs.push(node->left);
                }

                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    bfs.push(node->right);
                }

                if (parent.count(node) && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    bfs.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while (!bfs.empty()) {
            ans.push_back(bfs.front()->val);
            bfs.pop();
        }

        return ans;
    }
};