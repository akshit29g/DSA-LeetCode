class Solution {
public:
    long long minInitialStrength(vector<int>& monsters,
                                     vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<long long> diff(n + 1, 0);
        for (auto &b : boosts) {
            diff[b[0]] += b[2];
            if (b[1] + 1 < n)
                diff[b[1] + 1] -= b[2];
        }

        vector<long long> bonus(n);
        long long curBonus = 0;
        for (int i = 0; i < n; i++) {
            curBonus += diff[i];
            bonus[i] = curBonus;
        }

        auto can = [&](long long init) {
            long long cur = init;
            for (int i = 0; i < n; i++) {
                if (cur + bonus[i] < monsters[i])
                    return false;
                cur -= monsters[i];
                if (cur < 0)
                    cur = 0;
            }
            return true;
        };

        long long lo = 0, hi = 0;
        for (int x : monsters)
            hi += x;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (can(mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};