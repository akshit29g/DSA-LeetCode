class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n= nums.size();
        int less=0, equal=0;
        for (int x:nums){
            if (x<pivot) less++;
            else if (x==pivot) equal++;
        }
        vector<int> ans(n);
        int left=0;
        int mid=less;
        int right=less+equal;

        for (int x:nums){
            if (x<pivot) ans[left++]=x;
            else if (x==pivot) ans[mid++]=x;
            else ans[right++]=x;
        }
        return ans;
    }
};