class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        if(nums.empty()){
            vector<vector<int>> powerSet = {{}};
            return powerSet;
        }
        int t = nums[nums.size()-1];
        nums.pop_back();
        vector<vector<int>> result = subsets(nums);
        nums.push_back(t);
        int s = result.size();
        for(int i = 0 ; i< s ; i++){
            vector<int> temp = result[i];
            temp.push_back(t);
            result.push_back(temp);
        }
        return result;
    }
};
