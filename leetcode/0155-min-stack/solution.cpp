class MinStack {
    vector<vector<int>> memo;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int n = memo.size();
        if(memo.empty()){
            memo.push_back({val,val});
        }
        else{
            if(memo[n-1][1] > val){
                memo.push_back({val, val});
            }else{
                memo.push_back({val , memo[n-1][1]});
            }
        }
    }
    
    void pop() {
        memo.pop_back();
    }
    
    int top() {
        int num = memo[memo.size()-1][0];
        return num;
    }
    
    int getMin() {
        int num = memo[memo.size()-1][1];
        return num;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
