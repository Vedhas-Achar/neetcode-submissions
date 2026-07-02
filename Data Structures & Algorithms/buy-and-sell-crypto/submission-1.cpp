class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i<prices.size(); i++){
            int big = prices[i];
            for(int j = i+1; j<prices.size(); j++){
                if(prices[j] > big) big = prices[j];
            }
            profit = max(profit, (big-prices[i]));
        }
        return profit;
    }
};
