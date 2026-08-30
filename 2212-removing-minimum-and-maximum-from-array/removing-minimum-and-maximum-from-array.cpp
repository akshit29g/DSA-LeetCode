class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        vector<int> st;
        int maxi= *max_element(nums.begin(),nums.end());
        int mini= *min_element(nums.begin(),nums.end());
        for (int i=0;i<n;i++){
            if (nums[i]==maxi) st.push_back(i);
            if (nums[i]==mini) st.push_back(i);
        }
        int a= min(st[0],st[1]);
        int b= max(st[0],st[1]);
        int front= b+1;
        int back= n-a;
        int both= a+1+n-b;
        return min({front,back,both});
    }
};