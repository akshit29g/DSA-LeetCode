class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int aheadBuy, aheadNotbuy, currBuy, currNotbuy;
        for (int i=n-1;i>=0;i--){
            currBuy= max(-prices[i]+aheadNotbuy, aheadBuy);
            currNotbuy=  max(prices[i]+ aheadBuy, aheadNotbuy);
            aheadBuy=currBuy;
            aheadNotbuy=currNotbuy;
        }
        return aheadBuy;
    }
};