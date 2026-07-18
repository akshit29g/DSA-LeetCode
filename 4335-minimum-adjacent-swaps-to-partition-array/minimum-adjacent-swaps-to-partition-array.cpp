class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1e9 + 7;

        long long seenM = 0, seenH = 0;
        long long ans = 0;

        for (int x : nums) {
            if (x < a) {
                ans += seenM + seenH;
            }
            else if (x <= b) {
                ans += seenH;
                seenM++;
            }
            else {
                seenH++;
            }
        }

        return ans % MOD;
    }
};