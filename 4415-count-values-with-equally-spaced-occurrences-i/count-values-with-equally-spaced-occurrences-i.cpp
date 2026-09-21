class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;

        for (auto &[x, indices] : pos) {
            if (indices.size() == 3) {
                if (indices[1] - indices[0] == indices[2] - indices[1]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};