class Solution {
public:
    bool isValid(string s) {
        vector<char> memo;
        for(char q: s){
            int n = memo.size();
            if(q == '(' || q == '{' || q == '['){
                memo.push_back(q);
            }
            else if(q == ')'){
                if(n > 0 && memo[n-1] == '(') memo.pop_back();
                else return false;
            }
            else if(q == ']'){
                if(n > 0 && memo[n-1] == '[') memo.pop_back();
                else return false;
            }
            else if(q == '}'){
                if(n > 0 && memo[n-1] == '{') memo.pop_back();
                else return false;
            }
        }
        if(memo.size() == 0) return true;
        else return false;
    }
};
