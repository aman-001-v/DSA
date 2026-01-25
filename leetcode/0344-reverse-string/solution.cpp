class Solution {
public:
    void reverseString(vector<char>& s) {
        int p2 = s.size() -1;
        for(int p1 = 0 ; p1 < p2 ; p1++ , p2--){
            swap(s[p1],s[p2]);
        }
    }
};
