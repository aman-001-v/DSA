class Solution {
public:
    int romanToInt(string s) {
        map<char, int> memo = {{'I',1}, {'V',5},{'X',10},{'L',50}, {'C',100}, {'D',500}, 
                                {'M',1000}};
        int num = 0;
        for(int i = 0; i<s.length();i++){
            if(i==s.length()-1){
                num += memo[s[i]];
                break;
            }
            char s1 = s[i];
            char s2 = s[i+1];
            if(memo[s1] >= memo[s2]){
                num += memo[s1];
            }
            else{
                num -= memo[s1];
            }

        }
        return num;
    }
};
