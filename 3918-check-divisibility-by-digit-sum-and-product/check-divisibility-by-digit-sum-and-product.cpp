class Solution {
public:
    bool checkDivisibility(int n) {
        int original=n;
        vector<int> digits;
        while(n>0){
            digits.push_back(n%10);
            n/=10;
        }
        int sum=0, prod=1;
        for(int x:digits){
            sum+=x;
            prod*=x;
        }
        int total= sum+prod;
        return (original%total==0);
    }
};