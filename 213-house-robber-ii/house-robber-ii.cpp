class Solution {
public:
    int solve(vector<int>&nums,int l,int r) {
        int prev=0,curr=0;
        for(int i=l;i<=r;i++) {
            int pick=nums[i]+prev;
            int skip=curr;
            int temp=max(pick,skip);
            prev=curr;
            curr=temp;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        int case1=solve(nums,0,n-2);
        int case2=solve(nums,1,n-1);
        return max(case1,case2);
    }
};