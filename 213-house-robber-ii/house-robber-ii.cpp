class Solution {
public:
    int solve (vector<int>& nums){
        int n= nums.size();
        if (n==1) return nums[0];
        int prev2= nums[0];
        int prev= max(nums[0],nums[1]);
        for (int i=2;i<n;i++){
            int cur= max(prev, nums[i]+prev2);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if (n==1) return nums[0];
        vector<int> a(nums.begin(),nums.end()-1);
        vector<int> b(nums.begin()+1,nums.end());
        return max(solve(a),solve(b));
    }
};