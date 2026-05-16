class Solution {
public:
    set <vector<int>> s;
    void getAllCombinations(vector<int>& candidates, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin){
        if (idx==candidates.size()||tar<0){
            return;
        }
        if (tar==0){
            if (s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        combin.push_back(candidates[idx]);
        getAllCombinations(candidates,idx+1,tar-candidates[idx],ans,combin);

        getAllCombinations(candidates,idx,tar-candidates[idx],ans,combin);
        combin.pop_back();
        getAllCombinations(candidates,idx+1,tar,ans,combin);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombinations(candidates,0,target,ans,combin);
        return ans;
    }
};