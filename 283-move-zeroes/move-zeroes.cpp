class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int left=0, right=0;
        for (int i=0; i<n; i++){
            if (nums[right]!=0){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};