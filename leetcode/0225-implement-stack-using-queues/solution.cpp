class MyStack {
    queue<int> q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        while( --n != 0){
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
         int n = q1.size();
        while( --n != 0){
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
        int temp = q1.front();
        q1.pop();
        q1.push(temp);
        return temp;
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
