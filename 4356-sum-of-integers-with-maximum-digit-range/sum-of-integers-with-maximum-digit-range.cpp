class Solution {
public:
    int getRange(int x){
        int mn=9, mx=0;
        while (x>0){
            int d= x%10;
            mn= min(mn,d);
            mx= max(mx,d);
            x/=10;
        }
        return mx-mn;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxRange=0;
        for (int x:nums){
            maxRange= max(maxRange, getRange(x));
        }
        int sum=0;
        for (int x:nums){
            if (getRange(x)==maxRange){
                sum+= x;
            }
        }
        return sum;
    }
};