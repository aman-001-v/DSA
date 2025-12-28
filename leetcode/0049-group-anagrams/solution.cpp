class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> memo;
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            memo[key].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(const auto q:memo){
            result.push_back(q.second);
        }
        return result;
    }
};
