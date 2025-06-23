class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> check;
        queue<char> subString;
        int count_max = 0;
        for(int i = 0 ; i< s.length(); i++){
            char val = s[i];
            if(check.find(val) == check.end()){
                check.insert(val);
                subString.push(val);
            }else{
                count_max<subString.size()? count_max=subString.size():count_max = count_max;
                while(subString.front() != val){
                    check.erase(subString.front());
                    subString.pop();
                }
                subString.pop();
                subString.push(val);
            }
        }
        count_max<subString.size()? count_max=subString.size():count_max = count_max;
        return count_max;
    }
};
