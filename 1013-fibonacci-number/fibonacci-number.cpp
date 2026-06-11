class Solution {
public:
    int fib(int n) {
        if (n<=1) return n;
        int curr;
        int prev2=0;
        int prev=1;
        for (int i=2;i<=n;i++){
            curr= prev + prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};