class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> memo;
        for(int i = 0; i< nums.size(); i++){
            if(memo.count(nums[i])){
                return true;
            }
            memo.insert(nums[i]);
        }
        return false;
    }
};
