class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //if(s.length() == 1) return 1;
        int n = s.length();
        int left = 0;
        int right = 0;
        int count = 0;
        int max_count = 0;
        unordered_set<int> memo;
        while(right < n){
            if(memo.count(s[right])){
                max_count = max(max_count, count);
                while(s[left] != s[right]){
                    memo.erase(s[left++]);
                    count--;
                }
                left++;
            }else{
                memo.insert(s[right]);
                count++;
            }
            
            right++;
        }
        max_count = max(max_count, count);
        return max_count;
    }
};
