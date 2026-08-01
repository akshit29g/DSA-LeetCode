#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        // Step 1: Count frequencies of each plank height
        unordered_map<int, int> counts;
        for (int p : planks) {
            counts[p]++;
        }
        
        // Extract unique heights
        vector<int> unique_planks;
        unique_planks.reserve(counts.size());
        for (const auto& pair : counts) {
            unique_planks.push_back(pair.first);
        }
        
        // Map to store the maximum width for each constructible height
        unordered_map<int, int> ans;
        
        // Step 2: Calculate contributions for each constructible target height
        for (int i = 0; i < unique_planks.size(); ++i) {
            int v = unique_planks[i];
            int c = counts[v];
            
            // A single plank of height v contributes to target height v
            ans[v] += c;
            
            // Identical pairs of height v contribute to target height 2v
            if (c >= 2) {
                ans[2 * v] += c / 2;
            }
            
            // Distinct pairs of height v and u contribute to target height v + u
            for (int j = i + 1; j < unique_planks.size(); ++j) {
                int u = unique_planks[j];
                ans[v + u] += min(c, counts[u]);
            }
        }
        
        // Step 3: Find the maximum width out of all constructible target heights
        int max_w = 0;
        for (const auto& pair : ans) {
            max_w = max(max_w, pair.second);
        }
        
        return max_w;
    }
};