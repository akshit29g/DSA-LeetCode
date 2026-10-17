
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int x : nums) {
            int sum = 0, y = x;
            while (y > 0) {
                sum += y % 10;
                y /= 10;
            }
            arr.push_back({sum, x});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[nums[i]] == i)
                continue;

            int j = i, cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};
