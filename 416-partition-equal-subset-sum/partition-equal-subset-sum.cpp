class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int x:nums){
            sum+=x;
        }
        if (sum%2) return false;
        int target= sum/2;
        int n= nums.size();
        vector<bool> prev(target+1,0);
        prev[0]= true;
        if (nums[0]<=target){
            prev[nums[0]]=true;
        }
        for (int i=1;i<n;i++){
            vector<bool> cur(target+1,0);
            cur[0]= true;
            for (int t=1;t<=target;t++){
                bool notTake= prev[t];
                bool take= false;
                if (nums[i]<=t){
                    take= prev[t-nums[i]];
                }
                cur[t]= take || notTake;
            }
            prev=cur;
        }
        return prev[target];
    }
};