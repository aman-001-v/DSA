class Solution {
public:
    string decodeString(string s) {
        stack <string> memo;
        for(char e: s){
            string q = "";
            q += e;
            if(q != "]"){
                memo.push(q);
            }
            else{
                string str = "";
                while(!memo.empty() && memo.top() != "["){
                    str = memo.top() + str;
                    memo.pop();
                }
                memo.pop();
                string number = "";
                while(!memo.empty() && (memo.top() == "1" || memo.top() == "2" || memo.top() == "3" || memo.top() == "4" || memo.top() == "5" || memo.top() == "6" || memo.top() == "7" || memo.top() == "8" || memo.top() == "9" || memo.top() == "0")){
                    number = memo.top() + number;
                    memo.pop();
                }
                cout << number << endl;
                int num = stoi(number);
                number = "";
                for(int i = 0; i< num; i++){
                    number += str;
                }
                memo.push(number);
            }
        }
        string result = "";
        while(!memo.empty()){
            result = memo.top() + result;
            memo.pop();
        }
        return result;
    }
};
