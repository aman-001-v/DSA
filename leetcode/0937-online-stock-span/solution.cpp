class StockSpanner {
    stack <pair<int, int>> memo;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!memo.empty() && price >= memo.top().first){
            span += memo.top().second;
            memo.pop();
        }
        memo.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
