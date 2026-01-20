class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> memo;
        for(string q:tokens){
            if(q== "+"){
                int n1 = memo.top();
                memo.pop();
                int n2 = memo.top();
                memo.pop();
                memo.push(n2+n1);
            }else if(q == "-"){
                int n1 = memo.top();
                memo.pop();
                int n2 = memo.top();
                memo.pop();
                memo.push(n2-n1);
            }else if(q == "*"){
                int n1 = memo.top();
                memo.pop();
                int n2 = memo.top();
                memo.pop();
                memo.push(n1*n2);
            }else if(q == "/"){
                int n1 = memo.top();
                memo.pop();
                int n2 = memo.top();
                memo.pop();
                memo.push(n2/n1);
            }else{
                memo.push(stoi(q));
            }
        }
        return memo.top();
    }
};
