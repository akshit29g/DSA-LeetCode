class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, right=0;
        int currSum=0, res=INT_MAX;
        for (right=0;right<nums.size();right++){
            currSum+=nums[right];

            while(currSum>=target){
                res=min(res,right-left+1);
                currSum-=nums[left];
                left++;
            }
        }
        return res==INT_MAX ? 0:res;
    }
};