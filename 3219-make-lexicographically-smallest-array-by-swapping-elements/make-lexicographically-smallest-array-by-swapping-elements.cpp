class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // (value, original index)
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        // Sort by value
        sort(a.begin(), a.end());

        vector<int> ans = nums;

        int start = 0;

        while (start < n) {
            int end = start;

            // Find one connected group
            while (end + 1 < n &&
                   a[end + 1].first - a[end].first <= limit) {
                end++;
            }

            // Values in this group are already sorted
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(a[i].second);
            }

            // Put smaller values at smaller indices
            sort(indices.begin(), indices.end());

            for (int i = start; i <= end; i++) {
                ans[indices[i - start]] = a[i].first;
            }

            start = end + 1;
        }

        return ans;
    }
};