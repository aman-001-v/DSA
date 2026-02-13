class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        for(char c: t) need[c]++;

        int required = t.length();
        vector<int> have(128,0);
        int formed = 0;
        int minlen = INT_MAX , start = 0 , l = 0;

        for(int r = 0 ; r < s.length(); r++){
            int c = s[r];
            have[c]++;
            if(need[c] > 0 && have[c] <= need[c]) formed++;

            while(formed == required){
                if(r - l + 1 < minlen){
                    minlen = r-l+1;
                    start = l;
                }
                int left = s[l++];
                have[left]--;
                if(need[left] > 0 && have[left] < need[left]) formed--;

            
            }
        }
        return minlen == INT_MAX? "": string(s.begin() + start , s.begin() + start + minlen);
    }
};
