class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1){
            return s;
        }
        string longestStr = "";
        auto findPalindrome = [&](int left , int right){
            while(left>=0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            return s.substr(left + 1 , right - left - 1);
        };
        for(int i = 0 ; i< s.length()-1 ;i++){
            string subStrOdd = findPalindrome(i,i);
            string subStrEven = findPalindrome(i,i+1);
            if(subStrOdd.length() > longestStr.length() ) longestStr = subStrOdd;
            if(subStrEven.length() > longestStr.length() ) longestStr = subStrEven;
        }
        return longestStr;
    }
};
