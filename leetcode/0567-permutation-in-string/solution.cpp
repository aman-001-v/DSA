class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char , int> t;
        for(char q: s1){
            t[q]++;
        }
        int n = s2.length();
        int m = s1.length();
        int l = 0;
        int r = 0;
        unordered_map <char , int> memo = t;
        while(r < n && l < n){
            while(l < n && memo[s2[l]] == 0) l++;
            cout << l << endl;
            r=l;
            while(r < n && memo[s2[r]] != 0){
                memo[s2[r]]--;
                r++;
            }
            cout << r << " r" << endl;
            if(r - l >= m) return true;
            memo = t;
            l++;
        }
        return false;
    }
};
