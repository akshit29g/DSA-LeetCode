class Solution {
public:
    set<string> dfs(string &s, int &i) {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;

            if (s[i] == '{') {
                i++;
                cur = dfs(s, i);
                i++;
            } 
            else {
                cur.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (auto &a : res) {
                for (auto &b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;
        }

        set<string> finalRes = res;

        while (i < s.size() && s[i] == ',') {
            i++;

            set<string> next = dfs(s, i);
            finalRes.insert(next.begin(), next.end());
        }

        return finalRes;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = dfs(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};