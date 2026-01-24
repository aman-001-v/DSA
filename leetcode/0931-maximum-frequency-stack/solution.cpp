class FreqStack {
    unordered_map <int , stack<int>> memo;
    unordered_map<int,int> freq;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        memo[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);

    }
    
    int pop() {
        int t = memo[maxFreq].top();
        
        memo[maxFreq].pop();
        freq[t]--;
        if(memo[maxFreq].empty()) maxFreq--;
        return t;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
