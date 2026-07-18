class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n==1) return s;
        long long peakStart= 1LL*s+ 1LL*((n-1)/2)*(m-1);
        long long valleyStart= 1LL*s+ m+ 1LL*(n/2-1)*(m-1);
        return max(peakStart, valleyStart);
    }
};