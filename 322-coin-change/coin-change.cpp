class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
       vector<int> prev(amount+1,0), curr(amount+1,0);
        for (int t=0;t<=amount;t++){
            if (t%coins[0]==0) prev[t]= t/coins[0];
            else prev[t]= 1e9;
        }
        for (int ind=1;ind<n;ind++){
            for (int t=0;t<=amount;t++){
                int notTake= prev[t];
                int take= 1e9;
                if (coins[ind]<=t){
                    take= 1+ curr[t-coins[ind]];
                }
                curr[t]= min(notTake, take);
            }
            prev=curr;
        }
        int ans= prev[amount];
        return (ans>=1e9? -1: ans);
    }
};