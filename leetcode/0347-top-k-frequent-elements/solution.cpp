class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> memo;
        int n = nums.size();
        for(int i = 0 ; i< n ;i++){
            memo[nums[i]]++;
        }
        vector<int> result;
        while(k > 0){
            int max_key = memo.begin() -> first;
            int max_val = memo.begin() -> second;
            for(auto it = memo.begin(); it != memo.end() ; it++){
                if(it -> second > max_val){
                    max_key = it -> first;
                    max_val = it -> second;
                }
            }
            result.push_back(max_key);
            memo.erase(max_key);
            k--;
        }
        return result;
    }
};
