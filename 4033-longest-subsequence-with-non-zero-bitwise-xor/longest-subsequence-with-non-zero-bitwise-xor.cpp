class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            xr ^= x;
            if (x != 0)
                hasNonZero = true;
        }

        if (!hasNonZero)
            return 0;

        if (xr != 0)
            return nums.size();

        return nums.size() - 1;
    }
};