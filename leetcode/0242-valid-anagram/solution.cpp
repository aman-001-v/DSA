class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map <char, int> memo;
        for( char q : s){
            memo[q]++;
        }
        for(char q : t){
            auto it = memo.find(q);
            if(it == memo.end() || (it -> second) == 0) return false;
            --it -> second;
        }
        return true;
    }
};
