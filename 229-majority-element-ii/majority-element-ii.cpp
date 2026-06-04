class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n= nums.size();
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        for (auto &p:mp){
            if (p.second>n/3){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};