class Solution {
public:
    char major(unordered_map<char,int> &memo){
        int max = 0;
        char out;
        auto it = memo.begin();
        while(it != memo.end()){
            if(it -> second > max){
                out = it -> first;
                max = it -> second;
            }
            it++;
        }
        return out;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> memo;
        int l = 0;
        int r = 0;
        int result = 0;
        while(r < n){
            memo[s[r]]++;
            int m = memo[major(memo)];
            if(r-l+1 - m <= k){
                result = max( result , r-l+1);
            }else{
                while(r-l+1 - m > k){
                    memo[s[l]]--;
                    l++;
                } 
                result = max(result , r-l+1);
            }
            r++;
        }
        return result;
    }
};
