class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n= s.size();
        int m= p.size();
        if (m>n) return ans;
        vector<int> freqP(26,0);
        vector<int> window(26,0);

        for(char c:p){
            freqP[c-'a']++;
        }
        int left=0;
        for (int right=0; right<n; right++){
            window[s[right]-'a']++;

            if (right-left+1 > m){
                window[s[left]-'a']--;
                left++;
            }
            if (window==freqP){
                ans.push_back(left);
            }
        }
        return ans;
    }
};