class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0;
        string result = "";
        while(p1< word1.length() && p1 < word2.length()){
            result.push_back(word1[p1]);
            result.push_back(word2[p1++]);
        }
        while(p1 < word1.length()){
            result.push_back(word1[p1++]);
        }
        while(p1 < word2.length()){
            result.push_back(word2[p1++]);
        }
        return result;
    }
};
