class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<bool> seen(101,false);
        vector<bool> closed(101,false);
        int n= nums.size();
        for (int i=0;i<n;i++){
            int x= nums[i];
            if (seen[x] && i>0 && nums[i-1]!=x){
                closed[x]=true;
            }
            seen[x]=true;
        }
        int ans=0;
        for (int x=1;x<=100;x++){
            if (seen[x]&& !closed[x])
                ans++;
        }
        return ans;
    }
};