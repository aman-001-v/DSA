class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int left = 0;
        int right = 1;
        while(right < prices.size()){
            if(prices[right] > prices[left]){
                max_profit = max(max_profit, prices[right] - prices[left]);
            }
            else{
                left = right;
            }
            right++;
        }
        return max_profit;
    }
};
