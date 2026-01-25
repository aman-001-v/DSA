class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i<s.length(); i++){
            int n = (int)s[i];
            if(n>=65 && n <= 90 ){
                n += 32;
                s[i] = char(n);
            }
            else if(n >= 97 && n <= 122 || n >= 48 && n <= 57){
                continue;
            }else{
                s.erase(s.begin()+i--);
            }
        }
        //cout << s << endl;
        int end = s.length() -1;
        for(int st = 0; st< end; st++,end--){
            if(s[st] !=s[end]) return false;
        }
        return true;
    }
};
