class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string c_string_max = strs[0];
        for(int i = 1 ; i < strs.size() ; i++){
            string s1 = c_string_max;
            string s2 = strs[i];
            string c_str = "";
            int j = 0 , k = 0;
            while(s1[j] == s2[k] && j < s1.length() && k< s2.length()){
                c_str += s1[j++];
                k++;
            }
            c_string_max = c_str;
        }
        return c_string_max;
    }
};
